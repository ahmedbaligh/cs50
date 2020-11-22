SELECT johnny_movies.title
FROM (
    SELECT movies.title AS title, movies.id AS id
    FROM movies
    JOIN stars
    ON movies.id = stars.movie_id
    JOIN people
    ON stars.person_id = people.id
    WHERE people.name = 'Johnny Depp'
) AS johnny_movies
JOIN stars
ON johnny_movies.id = stars.movie_id
JOIN people
ON stars.person_id = people.id
WHERE people.name = 'Helena Bonham Carter';
