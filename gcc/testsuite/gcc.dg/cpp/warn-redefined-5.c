// { dg-do preprocess }
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Wno-macro-redefined" }
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
#define __STDC_TEST
#define __STDC_TEST	// something!
