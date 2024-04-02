CREATE DATABASE rfid_database;
USE rfid_database;

CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    UID VARCHAR(255) NOT NULL UNIQUE,
    username VARCHAR(255) NOT NULL, 
    email VARCHAR(255),
    tap_count INT DEFAULT 0
);

CREATE TABLE admins (
    admin_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    UID VARCHAR(255) NOT NULL UNIQUE,
);

INSERT INTO users(UID, username, email) VALUES("64A63141", "Ethan", "ewakefi@uwo.ca");
INSERT INTO users(UID, username, email) VALUES("E3B8E74F", "Taejun", "tha7@uwo.ca");

INSERT INTO admins(user_id,UID) VALUES(2,"E3B8E74F");

