CREATE DATABASE rfid_database;
USE rfid_database;

CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) NOT NULL, 
    email VARCHAR(255),
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