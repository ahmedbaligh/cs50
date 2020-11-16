import sys
import csv


def main():
    # Ensure correct usage
    if len(sys.argv) != 3:
        sys.exit('Usage: python dna.py data.csv sequence.txt')

    data = []
    # Read database of people's DNA into memory from file
    with open(sys.argv[1], 'r') as database:
        reader = csv.DictReader(database)
        # Append each person's data as a dictionary with a name and STR counts
        for row in reader:
            data.append(row)

    # Convert all STR counts to integers
    for row in data:
        for key in list(row.keys())[1:]:
            row[key] = int(row[key])

    # Read a person's DNA sequence into memory from file
    with open(sys.argv[2], 'r') as sequence:
        seq = sequence.read()

    # Look for a match, then print it
    match = find_match(data, seq)
    print(match)


def find_match(people, sequence):
    # Get the names and count of all STAs in database file
    stas = list(people[0].keys())[1:]
    stas_num = len(stas)

    # Find the highest number of consecutive repeats for each STA 
    stas_count = stas_max(sequence, stas)
    
    # Search each person in the database for a match
    for person in people:
        # Reset the matches count for each person
        match_count = 0

        # Check matches for each STA
        for sta in stas:
            # Increament the matches count by one, if the person's STA
            # matches the highest number for the same STA in the sequence
            if person[sta] == stas_count[sta]:
                match_count += 1
            # Otherwise, search matches for another person
            else:
                break

        # If a person matches all of the sequence's STAs, return their name 
        if match_count == stas_num:
            return person['name']
    
    # If no person has matches for all STAs, return 'No match'
    return 'No match'


def stas_max(seq, stas):
    data = {}
    for sta in stas:
        counter, max = 0, 0
        strings = seq.replace(sta, '-')
        for sub_string in strings:
            if sub_string == '-':
                counter += 1
                if max < counter:
                    max = counter
            else:
                counter = 0
        
        data[sta] = max
    
    return data


if __name__ == '__main__':
    main()
