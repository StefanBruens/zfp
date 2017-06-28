#include "src/encode1d.c"

#include "constants/1dDouble.h"
#include "utils/testMacros.h"
#include "utils/genSmoothRandNums.h"
#include "utils/hash64.c"
#include "zfpEndtoendBase.c"

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test_setup_teardown(when_seededRandomSmoothDataGenerated_expect_ChecksumMatches, setupFixedPrec, teardown),
    cmocka_unit_test_setup_teardown(given_1dDoubleArray_when_ZfpCompress_expect_BitstreamChecksumMatches, setupFixedPrec, teardown),
    cmocka_unit_test_setup_teardown(given_1dDoubleArray_when_ZfpDecompress_expect_ArrayChecksumMatches, setupFixedPrec, teardown),
    cmocka_unit_test_setup_teardown(given_1dDoubleArray_when_ZfpCompress_expect_BitstreamChecksumMatches, setupFixedRate, teardown),
    cmocka_unit_test_setup_teardown(given_1dDoubleArray_when_ZfpDecompress_expect_ArrayChecksumMatches, setupFixedRate, teardown),
    cmocka_unit_test_setup_teardown(given_1dDoubleFixedRate_when_ZfpCompress_expect_CompressedBitrateComparableToChosenRate, setupFixedRate, teardown),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}