## Package-delivery

- ### preprocess

  - xlsx => csv
  - calculate every route's **cost per weight unit**, and **arrival time** and save the results into **tools.csv**.

- ### problem 1

  - Using **IDDFS** (DFS with depth limit) to find paths from **seller\_city​** to **purchaser\_city** 
  - Deal with orders one by one. 

- ### problem 2

  - Set hubs according to the out-degree of each city, find the optimal route to a destination and regard it as the only transportation method from a hub to one place.

- ### problem 3

  - Add constraints in dfs 

- ### problem 4

  - 3 steps:
    - Search for big cities
    - walk among big cities
    - leave from big city and go to the destination