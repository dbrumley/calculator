# Mayhem Testing Example

Welcome to a simple example of how Mayhem can be used to improve a simple
calculator app. In a nutshell, Mayhem tries to test your app like a hacker
and help you check high level requirements in addition to specific unit tests.

Check out the PR to see how Mayhem works by:

- Performing security testing. Security testing searches and proves vulnerabililties  
  such as memory safety and logical bugs that violate a program invariant.

- Improving coverage. Mayhem continually looks for untested code and then writes a
  test case for it. The algorithm works as follows. Mayhem runs the app on
  a specific input, and notices which code branches are not executed. Those code
  branches are added to a queue. Mayhem then processes the queue and tries to write
  a test case that triggers a previously untested branch. Over time, this process helps
  grow your test suite to get more code coverage.

- Checking requirements with property testing. Unit tests only check a single
  test case, thus are insufficient for checking that general requirements hold.
  Property testing extends unit testing to check that all variations of a test
  satisfy an output condition.

  For example, Mayhem can check "A _ B / A = B", while normal unit tests can only check specific cases
  like "3 _ 2 / 3 = 2".

# Quick start

You can build this application quickly in two ways:

```
# docker build.
make docker

# On-system build. Requires make and a C compiler.
make all
```

# Running Mayhem

1. Go to https://mayhem.security and create an account.
2. Build the docker image as given in the quick start. Push the docker image to a public
   docker registry
3. Edit `tests/Mayhemfile` to point to your docker image.
4. Run `mayhem run -f tests/Mayhemfile`.
