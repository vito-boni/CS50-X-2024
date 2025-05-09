-- The average energy of songs that are by Drake
SELECT AVG(energy)
FROM songs
JOIN artists ON songs.artist_id = artists.id --23
WHERE artists.name = 'Drake';
