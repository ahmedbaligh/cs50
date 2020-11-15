from cs50 import get_int


def main():
    # Get height of the pyramid
    height = get_pyramid_height()

    # Create the pyramid
    for i in range(1, height + 1):
        # Align the pyramid to the right
        print(' ' * (height - i), end='')

        # Create each column of the pyramid
        print('#' * i)


def get_pyramid_height():
    while True:
        # Prompt the user for the pyramid's height
        h = get_int('Height: ')

        # Stop re-prompting, if the value is within the allowed range
        if h > 0 and h < 9:
            break
    
    return h


if __name__ == '__main__':
    main()