#include <stdio.h>
#include <string.h>
#include <SWI-Prolog.h>

#define MAXLINE 1024

/*
    small C program that makes a string of it's cmd line arguments,
   passes them to the calc/1 predicate in calc.pl, then
   prints the result
*/
int
main(int argc, char **argv)
{ char expression[MAXLINE];
  char *e = expression;
  char *program = argv[0];
  char *plav[3];
  int n;

  /* combine all the arguments in a single string 
     We will just pass the whole world to Prolog */

  for(n=1; n<argc; n++)
  { if ( n != 1 )
      *e++ = ' ';
    strcpy(e, argv[n]);
    e += strlen(e);
  }

  /* make the argument vector for Prolog */

  plav[0] = program;
  plav[1] = "--quiet";
  plav[2] = NULL;

  /* initialise Prolog */

int *isargc;
char ***isargv;

if(PL_is_initialised(isargc, isargv)) {
    printf("already inited\n");
    int j;
    for(j = 0 ; j < *isargc ; j++) {
        printf("argument %s\n", (*isargv)[j]);
    }
}  else {
    printf("not inited\n");
}
   

  if ( !PL_initialise(2, plav) )
    PL_halt(1);

printf("after initialise\n");

/*
if(PL_is_initialised(isargc, isargv)) {
    printf("inited\n");

    int j;
    for(j = 0 ; isargc, j < *isargc ; j++) {
        if(isargv && *isargv)
           printf("argument %s\n", (*isargv)[j]);
    }
}  else {
    printf("not inited after should be\n");
}
 */

  /* Lookup calc/1 and make the arguments and call */

  { predicate_t pred = PL_predicate("calc", 1, "user");
    term_t h0 = PL_new_term_refs(1);
    int rval;

    PL_put_atom_chars(h0, expression);
    rval = PL_call_predicate(NULL, PL_Q_NORMAL, pred, h0);

    PL_halt(rval ? 0 : 1);
  }

  return 0;
}
