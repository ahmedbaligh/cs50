SELECT AVG(songs.energy) from songs
JOIN artists
ON songs.artist_id = artists.id
WHERE artists.name = 'Drake';