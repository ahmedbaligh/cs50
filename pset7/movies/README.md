# Movies

Several SQL files, each containing a single query that answers a specific question.

The 13 questions/queries are:

1. List the titles of all movies released in 2008.
    
2. What is the birth year of Emma Stone?
        
3. List the titles of all movies with a release date on or after 2018, in alphabetical order.
    
4. What is the number of movies with an IMDb rating of 10.0?
        
5. List the titles and release years of all Harry Potter movies, in chronological order.
    
6. What is the average rating of all movies released in 2012?
    
7. List all movies released in 2010 and their ratings, in descending order by rating. For movies with the same rating, order them alphabetically by title.
        
8. List the names of all people who starred in Toy Story.
    
9. List the names of all people who starred in a movie released in 2004, ordered by birth year.
    
10. List the names of all people who have directed a movie that received a rating of at least 9.0.
    
11. List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
    
12. List the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.
    
13. List the names of all people who starred in a movie in which Kevin Bacon also starred.

## Getting Started

Execute ```wget https://cdn.cs50.net/2020/fall/psets/7/movies/movies.zip``` to download a (compressed) ZIP file containing this problem’s database file.

_Note that it will also have the empty `sql` files from the problem’s distribution._

## Usage

To run the queries, make sure to be in the `movies` directory, execute `cat <filename.sql> | sqlite3 movies.db` and the program's behaviour should be as per the examples below.

```
$ cat 11.sql | sqlite3 movies.db
42
Black Panther
Marshall
Get on Up
Draft Day
```

```
$ cat 5.sql | sqlite3 movies.db
Harry Potter and the Sorcerer's Stone|2001
Harry Potter and the Chamber of Secrets|2002
Harry Potter and the Prisoner of Azkaban|2004
Harry Potter and the Goblet of Fire|2005
Harry Potter and the Order of the Phoenix|2007
Harry Potter and the Half-Blood Prince|2009
Harry Potter and the Deathly Hallows: Part 1|2010
Harry Potter and the Deathly Hallows: Part 2|2011
Harry Potter and the Untold Stories of Hogwarts|2012
Harry Potter: A History of Magic|2017
```
