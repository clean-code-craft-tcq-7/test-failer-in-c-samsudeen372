# Testing Output Dependencies

Decomposition = Making smaller pieces of code - makes testing easier. Just as smaller sentences help us convey our intentions better.

Testing = Specifying the output - drives us to decompose better.

Welcome to Test Driven Development.

## The Task

This exercise has a set of buggy implementations. The implementations also have tests (asserts) which pass, despite the bugs. They are 'weak' tests.

Your task is to strengthen the tests and make them all fail.

In this repository, the workflows are designed to make the Action fail when any of the tests pass.

## Hints

`tshirts` has a simple error. It tries to classify T-shirt sizes based on shoulder-measurements. It leaves out one input value. Add a test to catch that.

`misaligned` tries to print a map from numbers to colors, as per [this Wiki](https://en.wikipedia.org/wiki/25-pair_color_code). However, the numeric values and the separator (`|`) are misaligned. The functionality is not efficiently testable - the fault needs human inspection. Think of separating the concerns and testing them individually.

`alerter` sends out an alert over the network when a threshold is breached. The code stubs the network-sendng part, so that we can test without the network.
