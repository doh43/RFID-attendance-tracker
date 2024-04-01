CREATE DATABASE rfid_database;
USE rfid_database;

/* For testing UID retrieval */
CREATE TABLE cards (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255)
);

CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    UID VARCHAR(255) NOT NULL UNIQUE,
    username VARCHAR(255) NOT NULL, 
    email VARCHAR(255)
);

CREATE TABLE admins (
    admin_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);

CREATE TABLE scans (
    scan_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT,  -- to record which user made the scan
    tag_id VARCHAR(255), -- RFID tag identifier
    scan_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);

INSERT INTO users(UID, username, email) VALUES("64A63141", "Ethan", "ewakefi@uwo.ca");
INSERT INTO users(UID, username, email) VALUES("E3B8E74F", "Taejun", "tha7@uwo.ca");

INSERT INTO scans(user_id, tag_id) VALUES(1, "ethantag");
INSERT INTO scans(user_id, tag_id) VALUES(2, "Taejuntag");
