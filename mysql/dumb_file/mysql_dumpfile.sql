-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimul
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `bank_account`
--

DROP TABLE IF EXISTS `bank_account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bank_account` (
  `id_account` int NOT NULL,
  `debit/credit` varchar(45) NOT NULL,
  `credit_limit` int DEFAULT NULL,
  `debit_balance` int NOT NULL,
  `credit_balance` int DEFAULT NULL,
  PRIMARY KEY (`id_account`),
  UNIQUE KEY `id_account_UNIQUE` (`id_account`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bank_account`
--

LOCK TABLES `bank_account` WRITE;
/*!40000 ALTER TABLE `bank_account` DISABLE KEYS */;
/*!40000 ALTER TABLE `bank_account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bank_card`
--

DROP TABLE IF EXISTS `bank_card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `bank_card` (
  `card_id` int NOT NULL AUTO_INCREMENT,
  `owner_id` int NOT NULL,
  `card_numer` varchar(45) NOT NULL,
  `pin_code` varchar(255) NOT NULL,
  `false_count` int DEFAULT NULL,
  `locked` int DEFAULT NULL,
  UNIQUE KEY `card_id_UNIQUE` (`card_id`),
  UNIQUE KEY `card_numer_UNIQUE` (`card_numer`),
  KEY `id_user_idx` (`owner_id`),
  CONSTRAINT `id_account` FOREIGN KEY (`card_id`) REFERENCES `bank_account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `id_user` FOREIGN KEY (`owner_id`) REFERENCES `user` (`user_id`) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bank_card`
--

LOCK TABLES `bank_card` WRITE;
/*!40000 ALTER TABLE `bank_card` DISABLE KEYS */;
/*!40000 ALTER TABLE `bank_card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transactions`
--

DROP TABLE IF EXISTS `transactions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transactions` (
  `id_transiction` int NOT NULL AUTO_INCREMENT,
  `account_number` int NOT NULL,
  `card_number` int NOT NULL,
  `transaction` varchar(45) NOT NULL,
  `ammount` int NOT NULL,
  `date_time` datetime NOT NULL,
  PRIMARY KEY (`id_transiction`),
  KEY `transaction-bank` (`account_number`),
  CONSTRAINT `transaction-bank` FOREIGN KEY (`account_number`) REFERENCES `bank_account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transactions`
--

LOCK TABLES `transactions` WRITE;
/*!40000 ALTER TABLE `transactions` DISABLE KEYS */;
/*!40000 ALTER TABLE `transactions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `user_id` int NOT NULL AUTO_INCREMENT,
  `fname` varchar(45) NOT NULL,
  `lname` varchar(45) NOT NULL,
  `ssn` varchar(45) NOT NULL,
  `user_number` int NOT NULL,
  `phone_number` int NOT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `user_id_UNIQUE` (`user_id`),
  UNIQUE KEY `user_number_UNIQUE` (`user_number`),
  UNIQUE KEY `ssn_UNIQUE` (`ssn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user/account`
--

DROP TABLE IF EXISTS `user/account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user/account` (
  `user_id` int NOT NULL,
  `id_account` int NOT NULL,
  PRIMARY KEY (`id_account`,`user_id`),
  KEY `id__user` (`user_id`),
  CONSTRAINT `account__id` FOREIGN KEY (`id_account`) REFERENCES `bank_account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `id__user` FOREIGN KEY (`user_id`) REFERENCES `user` (`user_id`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user/account`
--

LOCK TABLES `user/account` WRITE;
/*!40000 ALTER TABLE `user/account` DISABLE KEYS */;
/*!40000 ALTER TABLE `user/account` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-03-28 14:11:50
