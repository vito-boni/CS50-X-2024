-- The names of songs that are by Post Malone.
SELECT name
FROM songs
WHERE artist_id = -- 54
(
    SELECT id
    FROM artists
    WHERE name = 'Post Malone'
);
