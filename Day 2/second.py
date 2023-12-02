file = open("c:\\Users\\bkadmin\\Projects\\Github\\adventofcode-23\\Day 2\\input.txt", "rt")

red = 12
green = 13
blue = 14

known_set = [red, green, blue]
total = red + green + blue

colormap = {"red":0, "green":1, "blue":2}

games = [] 

for line in file:
    line = line[line.index(':') + 2:]
    sets = line.split("; ")
    new_sets = []
    
    for set in sets:
        colours = set.split(", ")
        new_colours = []
        for color in colours:
            value, color_name = color.strip("\n").split(" ")
            pair = [int(value), colormap[color_name]]
            new_colours.append(pair)
        new_sets.append(new_colours)
    games.append(new_sets)

    #sets = [list(map(lambda color: [int(color.split()[0]), colormap[color.split()[1]]], set.split(", "))) for set in line.split("; ")]
    #games.append(newsets)

#for index, game in enumerate(games):
#    print(f"Index: {index + 1}\n Game: {game}")

powers = []

for index, game in enumerate(games):
    print(f"\nIndex: {index + 1}\nGame: {game}")
    min_values = [0, 0, 0]
    for set in game:
        for pair in set:
            min_values[pair[1]] = max(pair[0], min_values[pair[1]])
    power = min_values[0] * min_values[1] * min_values[2]
    powers.append(power)
    print(f"Minimum values: {min_values}\nPower: {power}")

print(f"\n\nSum of powers: {sum(powers)}")

file.close()