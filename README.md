# Mayhem C example

This example repository shows how Mayhem can be integrated with a C
project to:
  * find vulnerabilities
  * increase code coverage
  * move beyond unit testing to semantic property testing.


The workflow demonstrated is:
  * The `main` branch has the calculator with unit tests in
    `unit_tests.c`. Without loss, we use `assert`. You can use any
    unit testing framework you wish.

The `new_feature_with_mayhem` branch
  [here](/dbrumley/calculator/tree/new_feature_with_mayhem) contains a
  new feature `factor_game`.  The game is used to illustrate the
  real-life difficulty of trying to come up with test cases for many
  code branches. 

The new feature branch also adds in Mayhem to:

  * finds the divide-by-zero in `divide`
  * demonstrates the power of Mayhem by checking properties like `a +
b = b + a` instead of simple unit tests like `2 + 1 = 3`
  * solve the `factor_game` automatically. 


To run the calculatorprogram, do:
```
echo "+ 4 1" | ./calculator    # calculates 4 + 1
echo "- 4 1" | ./calculator    # calculates 4 - 1
echo "* 4 1" | ./calculator    # calculates 4 * 1
echo "/ 4 1" | ./calculator    # calculates 4 / 1

# Run the game, guessing the solution is 10 and 11 (loses)
echo "g 10 11" | ./calculator 


# Run the game with the winning input. Winning corresponds to
# finding the vulnerable code path.
echo "g 7907 7919" | ./calculator
```
