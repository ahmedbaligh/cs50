def main():
    text = input('Text: ')

    # Count the number of letters, words, and sentences in the text
    letters, words, sentences = count(text)
    
    # Calculate average number of letters per 100 words
    L = (letters / words) * 100

    # Calculate average number of sentences per 100 words
    S = (sentences / words) * 100
    
    # Print the text's reading level grade
    coleman_liau_index(L, S)


def count(text):
    letter_counter, sentence_counter = 0, 0
    for char in text:
        # Count letters that are only alphabetic characters
        if char.isalpha():
            letter_counter += 1
        
        # Count sentences when an end-of-sentence character is reached 
        if char in ['.', '?', '!']:
            sentence_counter += 1

    # Calculate the number of words by counting words sperated by a space
    word_counter = len(text.split(' '))
    
    return letter_counter, word_counter, sentence_counter


def coleman_liau_index(L, S):
    # Compute the Coleman-Liau index
    index = round((0.0588 * L) - (0.296 * S) - 15.8)

    # Determine the text's reading grade
    if index < 1:
        print('Before Grade 1')
    elif index >= 16:
        print('Grade 16+')
    else:
        print(f'Grade {index}')


if __name__ == '__main__':
    main()