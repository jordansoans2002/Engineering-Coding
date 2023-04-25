

create table dwm.dim_location (
	location_id INT AUTO_INCREMENT,
    latitude INT NOT NULL,
    longitude int NOT NULL,
PRIMARY KEY(location_id));
    
CREATE TABLE dwm.dim_time (
	time_id INT AUTO_INCREMENT,
    year INT NOT NULL,
    day_of_year INT NOT NULL,
    hour INT NOT NULL,
PRIMARY KEY(time_id));

INSERT INTO dwm.dim_location VALUES
	(null,10,10),
    (null,20,15),
    (null,35,50),
    (null,19,21),
    (null,23,21);
    
INSERT INTO dwm.dim_time VALUES
    (null,2015,1,3),
    (null,2015,5,14),
    (null,2015,6,18),
    (null,2016,256,2),
   (null,2016,364,23);
CREATE TABLE dwm.fact_weather(
	loc_id INT NOT NULL,
    time_id INT NOT NULL,
    pressure  INT NOT NULL,
    temp INT NOT NULL,
    precipitation INT NOT NULL,
PRIMARY KEY(loc_id,time_id),
FOREIGN KEY(loc_id) REFERENCES dwm.dim_location(location_id),
FOREIGN KEY(time_id) REFERENCES dwm.dim_time(time_id));

select * from dwm.dim_time,dwm.dim_location;

INSERT INTO dwm.fact_weather VALUES
(1,1,1,23,10),(1,2,1,23,10),(1,3,1,23,10),
(1,4,1,23,10),(1,5,1,23,10),(2,1,1,23,10),
(2,2,1,23,10),(2,3,1,23,10),(2,4,1,23,10),
(2,5,1,23,10),(3,1,1,23,10),(3,2,1,23,10),
(3,3,1,23,10),(3,4,1,23,10),(3,5,1,23,10),
(4,1,1,23,10),(4,2,1,23,10),(4,3,1,23,10),
(4,4,1,23,10),(4,5,1,23,10),(5,1,1,23,10),
(5,2,1,23,10),(5,3,1,23,10),(5,4,1,23,10),
(5,5,1,23,10);

--rollup
SELECT dwm.dim_time.year, SUM(precipitation)
FROM dwm.fact_weather
INNER JOIN dwm.dim_time
ON dwm.fact_weather.time_id = dwm.dim_time.time_id
GROUP BY dwm.dim_time.year
with rollup;

--drill down
SELECT day_of_year,temp,precipitation,hour,longitude,latitude
FROM dwm.fact_weather
INNER JOIN dwm.dim_time
ON dwm.fact_weather.time_id = dwm.dim_time.time_id
INNER JOIN dwm.dim_location
ON dwm.fact_weather.loc_id = dwm.dim_location.location_id
WHERE year=2015
GROUP BY day_of_year;

--slice
SELECT loc_id,time_id,pressure,temp,precipitation,latitude,longitude
FROM fact_weather
INNER JOIN dim_location
ON dwm.fact_weather.loc_id = dwm.dim_location.location_id
WHERE year=2015;

-dice
SELECT loc_id,fact_weather.time_id,pressure,temp,precipitation,latitude,longitude,year
FROM fact_weather
INNER JOIN dim_location
ON dwm.fact_weather.loc_id = dwm.dim_location.location_id
INNER JOIN dwm.dim_time
ON dwm.fact_weather.time_id = dwm.dim_time.time_id
WHERE year = 2015 AND longitude=50;


