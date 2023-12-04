package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"unicode"
)

const (
	rows = 140
	coloumbs = 140
)

func IsSymbol(c rune) bool {
	if c == '#' || c == '=' || c == '*' || c == '%' || c == '&' ||
	   c == '+' || c == '@' || c == '$' || c == '-' || c == '\\' ||
	   c == '/' || c == '?' || c == '`' || c == '~' || c == '|' {
		return true
	}

	return false
}

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
	}
	defer func() {
        if err = file.Close(); err != nil {
            log.Fatal(err)
        }
    }()

	arr := make([]string, rows)

	sc := bufio.NewScanner(file)
	n := 0
    for sc.Scan() {
		if n < rows {
			arr[n] = sc.Text() 
			//fmt.Println(arr[n] + "\n")
		} else {
			break
		}
		n++
    }

    if err := sc.Err(); err != nil {
        log.Fatalf("scan file error: %v", err)
        return
    }

	sum := 0
	for i, line := range arr {
		fmt.Println("\n==================================  N E W   L I N E  ==================================")
		startIdx := -1
		endIdx := -1
		countme := false
		for j, c := range line {	
			isDigit := unicode.IsDigit(c)

			if isDigit && startIdx < 0 {
				startIdx = j
			}
			if isDigit && startIdx > -1 {
				endIdx = j
			}

			if (j == coloumbs -1 || !isDigit) && (startIdx > -1 && endIdx > -1) {
				curnum := line[startIdx:endIdx+1]
				fmt.Println("\nCurrent number: " + curnum)

				if startIdx > 0 {
					if IsSymbol(rune(line[startIdx-1])) {
						countme = true
					}
				}
				if endIdx < coloumbs -1 && countme == false {
					if IsSymbol(rune(line[endIdx+1])) {
						countme = true
					}
				}

				if i > 0 && countme == false {
					prev := arr[i-1]
					fmt.Println("Checking prev")
					fmt.Println(prev)
					if startIdx > 0 {
						if IsSymbol(rune(prev[startIdx-1])) {
							countme = true
						}
					}	
					if endIdx < coloumbs - 1 {
						if IsSymbol(rune(prev[endIdx+1])) {
							countme = true
						}
					}

					for a := startIdx; a <= endIdx; a++ {
						if IsSymbol(rune(prev[a])) {
							countme = true
							break
						}
					} 
				}
				fmt.Println(line)

				if i < rows -1 && countme == false {
					next := arr[i+1]
					fmt.Println("Checking next")
					fmt.Println(next)
					if startIdx > 0 {
						if IsSymbol(rune(next[startIdx-1])) {
							countme = true
						}
					}
					if endIdx < coloumbs - 1 {
						if IsSymbol(rune(next[endIdx+1])) {
							countme = true
						}
					}

					for a := startIdx; a <= endIdx; a++ {
						if IsSymbol(rune(next[a])) {
							countme = true
							break
						}
					} 
				}

				if countme {
					val, err := strconv.Atoi(line[startIdx:endIdx+1])
					if err != nil {
						log.Fatal(err)	
					}
					sum += val
					fmt.Printf("======== Found %d ========\n", val)
					countme = false
				}	

				startIdx = -1
				endIdx = -1	
			}
		}
	}
	fmt.Printf("\n\nSum: %d\n", sum)
}