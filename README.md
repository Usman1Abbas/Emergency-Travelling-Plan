# Traveler's Emergency Return Solution

This repository contains a solution for the problem of a traveler needing to return to the office due to an emergency meeting. The traveler is in a scenario where they need to navigate through different cities connected by both road and air routes, with the goal of reaching their destination in the minimum number of days while adhering to certain constraints.

## Problem Description

The problem is as follows:

- The traveler is visiting different places and receives an emergency call to return to the office.
- There are cities connected through road networks, and some also have air connections.
- The traveler can travel up to 6 cities in one day if traveling by road.
- Once the traveler reaches a city with an aerial route, they must continue to the other destination of the aerial route by the end of the same day.
- The traveler cannot stop in a city where there is an aerial route taking them back to previously visited cities.

## Solution Approach

The solution provided in this repository aims to find the minimum number of days required for the traveler to return to their destination city. This is achieved by employing a strategy that optimizes the use of road and air routes while avoiding revisiting cities unnecessarily.

## How to Use

To use this solution, follow these steps:

1. **Input Data**: Provide the input data specifying the cities, their connections through road and air routes, and any constraints such as maximum cities to travel in one day.
2. **Run Algorithm**: Execute the algorithm provided in the repository to compute the minimum days required for the traveler to return to the destination.
3. **Output**: The output will be the minimum number of days required for the traveler to reach the destination city, along with the route plan indicating the cities to visit each day.

## Example

Consider the following scenario:
- The traveler needs to move from city 1 to city 30 in as minimum days as possible.
- City 2 has an aerial route to city 21.
- The traveler can travel up to 6 cities by road in one day.

Based on the example provided, the algorithm computes the optimal route, which involves taking the aerial route from city 2 to city 21 on day 1, then continuing the journey via road until reaching the destination city 30. The minimum days required for this journey is 3 days.

## Contributors

- Muhammad Usman

