// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
#include <behavior/dynamic_batch.hpp>
#include "common_test_utils/test_constants.hpp"

namespace BehaviorTestsDefinitions {
namespace {
std::vector<size_t> batch_sizes = {
    1,
    5,
    9,
    16
};

std::map<std::string, std::string> additional_config = {
};
} // namespace


INSTANTIATE_TEST_CASE_P(smoke_DynamicBatchTest_async, DynamicBatchTest,
    ::testing::Combine(
        ::testing::Values(CommonTestUtils::DEVICE_CPU),
        ::testing::Values(InferenceEngine::Precision::FP32),
        ::testing::Values(batch_sizes),
        ::testing::Values(true),
        ::testing::Values(additional_config)),
    DynamicBatchTest::getTestCaseName);

INSTANTIATE_TEST_CASE_P(smoke_DynamicBatchTest_sync, DynamicBatchTest,
    ::testing::Combine(
        ::testing::Values(CommonTestUtils::DEVICE_CPU),
        ::testing::Values(InferenceEngine::Precision::FP32),
        ::testing::Values(batch_sizes),
        ::testing::Values(false),
        ::testing::Values(additional_config)),
    DynamicBatchTest::getTestCaseName);
} // namespace BehaviorTestsDefinitions
