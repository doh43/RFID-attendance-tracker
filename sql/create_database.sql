CREATE DATABASE rfid_database;
USE rfid_database;
CREATE TABLE scans (id INT AUTO_INCREMENT PRIMARY KEY, tag_id VARCHAR(255), scan_time TIMESTAMP);