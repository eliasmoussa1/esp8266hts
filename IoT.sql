SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";
--
-- Table structure for table `IoT`
--

CREATE TABLE IF NOT EXISTS `readings` (
`entry_id` bigint(20) NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `iot_id` text NOT NULL,
  `property` text NOT NULL,
  `value` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `IoT`
--
ALTER TABLE `readings`
 ADD PRIMARY KEY (`entry_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `IoT`
--
ALTER TABLE `readings`
MODIFY `entry_id` bigint(20) NOT NULL AUTO_INCREMENT;
