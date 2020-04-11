# Project 2 Spell Checker

## How to run?
To run my program, you need an english.txt file. If you have this file,
you can do the following command <code>make</code> this will create an executable which can be ran by doing <code>./run</code>
Without the english.txt file in the directory where this program is located, this program will not work. It needs to contain one word on each line, can be capitalized or non capitalized. The file must be named "english.txt" for this program to work

## What does it do?
This program is a Spell Check program that takes a dictionary or "english.txt" file, full of words and inserts them into a Hash Table to be used as a reference for words used in a sentence or paragraph. Then, the program will prompt you to enter a word, phrase, sentence, or paragraph you would like to have spell checked. My program will return the misspelled words and return a list of suggestions as to what this word could be replaced with based on the words from the dictionary in my Hash Table.
