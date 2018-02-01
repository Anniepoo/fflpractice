# Foreign Language Interface Example

I don't know where this is from. If it's yours, please let me know.

I may have gotten this from Jan.

## building

Obviously you need SWI-Prolog installed

swipl-ld -o calc calc.c calc.pl

This creates the executable calc from calc.c and calc.pl

http://www.swi-prolog.org/pldoc/man?section=plld

## run

The program is a small calculator, done using atom_term to parse followed by is/2 to perform the calculation and prints it.

./calc 2+2






