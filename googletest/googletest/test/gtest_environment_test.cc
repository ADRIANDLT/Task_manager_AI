// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//
// Tests using global test environments.

#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"
#include "src/gtest-internal-inl.h"

namespace {

enum FailureType { NO_FAILURE, NON_FATAL_FAILURE, FATAL_FAILURE };

// Was SetUp run?
bool set_up_was_run;
// Was TearDown run?
bool tear_down_was_run;
// Was the TEST run?
bool test_was_run;

// For testing using global test environments.
class MyEnvironment : public testing::Environment {
 public:
  // Depending on the value of failure_in_set_up_, SetUp() will
  // generate a non-fatal failure, generate a fatal failure, or
  // succeed.
  void SetUp() override {
    set_up_was_run = true;

    switch (failure_in_set_up_) {
      case NON_FATAL_FAILURE:
        ADD_FAILURE() << "Expected non-fatal failure in global set-up.";
        break;
      case FATAL_FAILURE:
        FAIL() << "Expected fatal failure in global set-up.";
        break;
      default:
        break;
    }
  }

  // Generates a non-fatal failure.
  void TearDown() override {
    tear_down_was_run = true;
    ADD_FAILURE() << "Expected non-fatal failure in global tear-down.";
  }

  // We call this function to set the type of failure SetUp() should
  // generate.
  void set_failure_in_set_up(FailureType type) { failure_in_set_up_ = type; }

 private:
  FailureType failure_in_set_up_;
};

// The sole purpose of this TEST is to enable us to check whether it
// was run.
TEST(FooTest, Bar) { test_was_run = true; }

// Prints the message and aborts the program if condition is false.
void Check(bool condition, const char* msg) {
  if (!condition) {
    printf("FAILED: %s\n", msg);
    testing::internal::posix::Abort();
  }
}

// Runs the tests.  Return true if and only if successful.
//
// The 'failure' parameter specifies the type of failure that should
// be generated by the global set-up.
int RunAllTests(MyEnvironment* env, FailureType failure) {
  set_up_was_run = false;
  tear_down_was_run = false;
  test_was_run = false;
  env->set_failure_in_set_up(failure);
  testing::internal::GetUnitTestImpl()->ClearAdHocTestResult();
  return RUN_ALL_TESTS();
}

// Registers a global test environment, and verifies that the
// registration function returns its argument.
MyEnvironment* RegisterTestEnv() {
  MyEnvironment* const env = new MyEnvironment;
  Check(testing::AddGlobalTestEnvironment(env) == env,
        "AddGlobalTestEnvironment() should return its argument.");
  return env;
}

// Verifies that RUN_ALL_TESTS() runs the tests when the global
// set-up is successful.
void TestGlobalSetUp() {
  MyEnvironment* const env = RegisterTestEnv();
  Check(RunAllTests(env, NO_FAILURE) != 0,
        "RUN_ALL_TESTS() should return non-zero, as the global tear-down "
        "should generate a failure.");
  Check(test_was_run,
        "The tests should run, as the global set-up should generate no "
        "failure");
  Check(tear_down_was_run,
        "The global tear-down should run, as the global set-up was run.");
}

// Verifies that RUN_ALL_TESTS() runs the tests when the global
// set-up generates no fatal failure.
void TestTestsRun() {
  MyEnvironment* const env = RegisterTestEnv();
  Check(RunAllTests(env, NON_FATAL_FAILURE) != 0,
        "RUN_ALL_TESTS() should return non-zero, as both the global set-up "
        "and the global tear-down should generate a non-fatal failure.");
  Check(test_was_run,
        "The tests should run, as the global set-up should generate no "
        "fatal failure.");
  Check(tear_down_was_run,
        "The global tear-down should run, as the global set-up was run.");
}

// Verifies that RUN_ALL_TESTS() runs no test when the global set-up
// generates a fatal failure.
void TestNoTestsRunSetUpFailure() {
  MyEnvironment* const env = RegisterTestEnv();
  Check(RunAllTests(env, FATAL_FAILURE) != 0,
        "RUN_ALL_TESTS() should return non-zero, as the global set-up "
        "should generate a fatal failure.");
  Check(!test_was_run,
        "The tests should not run, as the global set-up should generate "
        "a fatal failure.");
  Check(tear_down_was_run,
        "The global tear-down should run, as the global set-up was run.");
}

// Verifies that RUN_ALL_TESTS() doesn't do global set-up or
// tear-down when there is no test to run.
void TestNoTestsSkipsSetUp() {
  MyEnvironment* const env = RegisterTestEnv();
  GTEST_FLAG_SET(filter, "-*");
  Check(RunAllTests(env, NO_FAILURE) == 0,
        "RUN_ALL_TESTS() should return zero, as there is no test to run.");
  Check(!set_up_was_run,
        "The global set-up should not run, as there is no test to run.");
  Check(!tear_down_was_run,
        "The global tear-down should not run, "
        "as the global set-up was not run.");
}

}  // namespace

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);

  TestGlobalSetUp();
  TestTestsRun();
  TestNoTestsRunSetUpFailure();
  TestNoTestsSkipsSetUp();

  printf("PASS\n");
  return 0;
}