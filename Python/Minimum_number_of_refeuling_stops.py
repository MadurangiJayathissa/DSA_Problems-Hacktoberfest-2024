import heapq 

def minRefuelStops(target, startFuel, stations):
    # Number of gas stations
    n = len(stations)

    # dp[i] is the maximum distance we can reach with i refueling stops
    dp = [0] * (n + 1)
    dp[0] = startFuel

    # Iterate over each station
    for i in range(n):
        # station[i] gives (distance to station, fuel at station)
        station_distance, fuel_at_station = stations[i]
        
        # Traverse dp array from end to start to avoid overwriting previous results
        for j in range(i, -1, -1):
            # If we can reach this station with j refuels
            if dp[j] >= station_distance:
                # Update dp[j + 1] with max distance after refueling
                dp[j + 1] = max(dp[j + 1], dp[j] + fuel_at_station)
    
    # Find the minimum refuels needed to reach the target
    for i in range(n + 1):
        if dp[i] >= target:
            return i

    # If it's not possible to reach the target
    return -1

# Example usage:
target = 100
startFuel = 10
stations = [[10, 60], [20, 30], [30, 30], [60, 40]]

# Calling the function
result = minRefuelStops(target, startFuel, stations)
print(f"Minimum number of refueling stops: {result}")
