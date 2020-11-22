SELECT DISTINCT(people.name)
FROM (
    SELECT movies.id AS movie_id
    FROM movies
    JOIN stars
    ON movies.id = stars.movie_id
    JOIN people
    ON stars.person_id = people.id
    WHERE people.name = 'Kevin Bacon' AND people.birth = 1958
) AS co_stars
JOIN stars
ON co_stars.movie_id = stars.movie_id
JOIN people
ON stars.person_id = people.id
WHERE people.name != 'Kevin Bacon';
