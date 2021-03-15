package main

import (
	"fmt"
	"regexp"
	"math"
	"strings"
	"unicode"
)
// SplitOnNonLetters splits a string on non-letter runes
func SplitOnNonLetters(s string) []string {
	notALetter := func(char rune) bool { return !unicode.IsLetter(char)	}
	return strings.FieldsFunc(s, notALetter)
}

var str = "Мир - парк поезд. А куда ты! Мир парк"
//var str1 = "Мир - парк1 поезд. А куда ты! Мир парк"
func main() {
	fmt.Println(str)
	//text := map[string]uint32
	test := make(chan map[string]uint32)
	words := regexp.MustCompile("[*.?!]{1} ").Split(str, -1)
	for _, word := range words {
		str = strings.ToLower(word)
		parts := SplitOnNonLetters(str)
		go ngrams(parts, 2,test)
	}
	for i ,_   := range words {
		fmt.Println(i)
		t := <- test
 		fmt.Println(t)
	}
}

func ngrams(words []string, size int,test chan map[string]uint32) {

	count := make(map[string]uint32, 0)
	offset := int(math.Floor(float64(size / 2)))

	max := len(words)
	for i := range words {
		if i < offset || i+size-offset > max {
			continue
		}
		gram := strings.Join(words[i-offset:i+size-offset], " ")
		count[gram]++
	}
	test <-  count
	 
}
