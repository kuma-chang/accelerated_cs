#!/usr/bin/env python3

import sys
import os.path
import re

def read_input(input_name):
    input_data = []

    with open(input_name + ".input", 'r') as input_file:
        input_size = int(input_file.readline())
        for i in range(input_size):
            input_data.append(input_file.readline().split()[0].split(','))
    return input_data

def get_bargains(input_data):
    purchase_sum = 0.0
    bargains = []
    for each_input in input_data:
        purchase_sum = purchase_sum + (float(each_input[0]) * float(each_input[4]))

    purchase_average = purchase_sum / len(input_data)

    for each_input in input_data:
        if (float(each_input[0]) * float(each_input[4])) < (purchase_average * 1.5):
            if each_input[2] == "superior" or each_input[3] == "blue":
                bargains.append(each_input[1])
    
    return bargains

def print_bargains(bargains):
    print("Bargains: ")
    for bargain in bargains:
        print(bargain)



def usage():
  print('usage: ./bargains.py file.input')    
  exit(0)

def main():
  if len(sys.argv) < 2: usage()    
  f = sys.argv[1]
  input_name,kind = os.path.splitext(f)
  if kind == '.input':
    if len(sys.argv) != 2: usage()
    input_data = read_input(input_name)
  else: usage()
  bargains = get_bargains(input_data)
  print_bargains(bargains)
  
if __name__ == '__main__':
  main()
