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

validgames = list(range(1,101))

for index, game in enumerate(games):
    for set in game:
        invalid = False
        if total <= sum(pair[0] for pair in set): # or (pairk[0] < known_set[pairk[1]] for pairk in set):
            print(f"Invalid game found! Index: {index + 1}")
            validgames.remove(index+1)
            break
        
        for pair in set:
            if pair[0] > known_set[pair[1]]:
                print(f"Invalid game found! Index: {index + 1}")
                validgames.remove(index+1)
                invalid = True
                break
        if invalid:
            break


print(validgames)
print(sum(validgames))

file.close()