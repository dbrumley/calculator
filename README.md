# Mayhem C example

This example repository shows how Mayhem can be integrated with a C
project to:
  * find bugs
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

