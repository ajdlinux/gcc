// { dg-do preprocess }
// { dg-options "-std=gnu99 -fdiagnostics-show-option -Werror=macro-redefined" }
/* { dg-message "some warnings being treated as errors" "" {target "*-*-*"} 0 } */
#ifndef __TIME__
#error "__TIME__ builtin is not defined"
// { dg-bogus "__TIME__ builtin is not defined" "no-time" { target *-*-* } 5 }
#endif

#define __TIME__ "X"  // { dg-warning "\"__TIME__\" redefined .-Werror=builtin-macro-redefined." }

#define __TIME__ "Y"  // { dg-bogus "-Wbuiltin-macro-redefined" }
                      // { dg-warning "\"__TIME__\" redefined .-Wmacro-redefined." "not-builtin-1" { target *-*-* } 11 }
                      // { dg-message "previous definition" "previous-1" { target *-*-* } 9 }

#define X "X"
#define X "Y"         // { dg-bogus "-Wbuiltin-macro-redefined" }
                      // { dg-error "\"X\" redefined .-Wmacro-redefined." "not-builtin-2" { target *-*-* } 16 }
                      // { dg-message "previous definition" "previous-2" { target *-*-* } 15 }

// what this does:
//  same as test #1, but it should ERROR on the X redefinition, not the __TIME__ redefintiion
// TODO: Update to ensure it matches for a -Wmacro-redefined string!
