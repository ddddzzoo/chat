DROP TABLE IF EXISTS `allgroup`;

CREATE TABLE `allgroup` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `groupname` varchar(50) NOT NULL,
  `groupdesc` varchar(200) DEFAULT '',
  PRIMARY KEY (`id`),
  UNIQUE KEY `groupname` (`groupname`)
) ENGINE = InnoDB AUTO_INCREMENT = 2 DEFAULT CHARSET = utf8mb4;

INSERT INTO
  `allgroup`
VALUES
  (
    1,
    'C++ chat project',
    'start develop a chat project'
  );

DROP TABLE IF EXISTS `friend`;

CREATE TABLE `friend` (
  `userid` int(11) NOT NULL,
  `friendid` int(11) NOT NULL,
  KEY `userid` (`userid`, `friendid`)
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;

INSERT INTO
  `friend`
VALUES
  (13, 15),
  (13, 21),
  (21, 13),
  (21, 15);

DROP TABLE IF EXISTS `groupuser`;

CREATE TABLE `groupuser` (
  `groupid` int(11) NOT NULL,
  `userid` int(11) NOT NULL,
  `grouprole` enum('creator', 'normal') DEFAULT NULL,
  KEY `groupid` (`groupid`, `userid`)
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;

INSERT INTO
  `groupuser`
VALUES
  (1, 13, 'creator'),
  (1, 21, 'normal'),
  (1, 19, 'normal');

DROP TABLE IF EXISTS `offlinemessage`;

CREATE TABLE `offlinemessage` (
  `userid` int(11) NOT NULL,
  `message` varchar(500) NOT NULL
) ENGINE = InnoDB DEFAULT CHARSET = utf8mb4;

INSERT INTO
  `offlinemessage`
VALUES
  (
    19,
    '{"groupid":1,"id":15,"msg":"hello","msgid":10,"name":"li si","time":"2024-02-22 00:43:59"}'
  ),
  (
    19,
    '{"groupid":1,"id":15,"msg":"helo!!!","msgid":10,"name":"li si","time":"2024-02-22 22:43:21"}'
  ),
  (
    19,
    '{"groupid":1,"id":13,"msg":"hahahahaha","msgid":10,"name":"zhang san","time":"2024-02-22 22:59:56"}'
  ),
  (
    19,
    '{"groupid":1,"id":13,"msg":"hahahahaha","msgid":10,"name":"zhang san","time":"2024-02-23 17:59:26"}'
  ),
  (
    19,
    '{"groupid":1,"id":15,"msg":"wowowowowow","msgid":10,"name":"li si","time":"2024-02-23 17:59:34"}'
  );

DROP TABLE IF EXISTS `user`;

CREATE TABLE `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL,
  `state` enum('online', 'offline') DEFAULT 'offline',
  PRIMARY KEY (`id`),
  UNIQUE KEY `name` (`name`)
) ENGINE = InnoDB AUTO_INCREMENT = 22 DEFAULT CHARSET = utf8mb4;

INSERT INTO
  `user`
VALUES
  (13, 'zhang san', '123456', 'online'),
  (15, 'li si', '666666', 'offline');