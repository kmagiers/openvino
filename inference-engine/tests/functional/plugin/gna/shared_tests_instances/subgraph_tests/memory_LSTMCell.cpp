#include <subgraph_tests/memory_LSTMCell.hpp>
#include "common_test_utils/test_constants.hpp"

namespace SubgraphTestsDefinitions {
    std::vector<size_t> input_sizes = {
        80,
    };

    std::vector<size_t> hidden_sizes = {
        128,
    };

    std::map<std::string, std::string> additional_config = {
        {"GNA_COMPACT_MODE", "NO"},
        {"GNA_DEVICE_MODE", "GNA_SW_EXACT"},
        {"GNA_SCALE_FACTOR_0", "1600"},
    };

    INSTANTIATE_TEST_CASE_P(MemoryLSTMCellTest, MemoryLSTMCellTest,
        ::testing::Combine(
            ::testing::Values(CommonTestUtils::DEVICE_GNA),
            ::testing::Values(InferenceEngine::Precision::FP32),
            ::testing::ValuesIn(input_sizes),
            ::testing::ValuesIn(hidden_sizes),
            ::testing::Values(additional_config)),
        MemoryLSTMCellTest::getTestCaseName);
} // SubgraphTestsDefinitions
