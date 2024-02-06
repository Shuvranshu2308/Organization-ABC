# 1. NEED TO READ DATA FROM FILE IN A LIST
print("READING DATA FROM TEXT FILE TO THE LIST:")
try:
    file = open("Sample.txt", "r")
    data = file.read()
    file_to_list = data.replace('\n', ' ').split()
    print(file_to_list)
    print("___________________")
    file.close()
except IOError:
    print("The data does not exist in the file")


# 2. USE FILTER AND MAP HIGHER ORDER FUNCTIONS TO DO SOME MODIFICATIONS
print("COUNTING THE LENGTH OF EACH STRING IN THE LIST USING MAP() :")
try:
    length_of_each_string = list(map(len,file_to_list))
    print(length_of_each_string)
except IOError:
    print("Length cannot be determined")

    print("CONVERT EACH STRING IN THE LIST UPPERCASE TO LOWER CASE :")
try:
    new_names = list(map(lambda name: name.upper(), file_to_list))
    print(new_names)
except IOError:
    print("Invalid Operation")


# 3. SORTING THE LIST
print("LIST AFTER SORTING :")
try:
    new_names.sort(reverse=True)
    print(new_names)
except IOError:
    print("Sorting cannot be performed")


# USING FILTER()TO GET THE LENGTH OF STRING GRATER THAN
print("LENGTH OF 5 LETTER WORD : ")
try:
    filtered = filter(lambda e: len(e) == 5, new_names)
    print(list(filtered))
except IOError:
    print("No string of length 5 is found")


# 4. STORING THE LIST INTO THE FILE BACK
try:
    storing_file = open("Sample.txt", "w")
    for element in new_names:
        storing_file.write(element+"\n")
    storing_file.close()
except IOError:
    print("Can not find the error")
