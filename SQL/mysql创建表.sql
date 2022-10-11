DROP TABLE IF EXISTS `student`;#判断时候存在，若存在则执行删除表操作
CREATE TABLE `student` (
  `s_id` varchar(40) NOT NULL,
  `s_name` varchar(255) default NULL,
  `s_age` varchar(255) default NULL,
  `s_msg` varchar(255) default NULL,
  PRIMARY KEY  (`s_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
 
-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES ('1', '早晨', '22', '电风扇');
INSERT INTO `student` VALUES ('2', '春节', '32', '发电设备v');
INSERT INTO `student` VALUES ('3', '端午节', '33', '地方');
INSERT INTO `student` VALUES ('4', '清明节', '44', 'dfs ');
INSERT INTO `student` VALUES ('5', '圣诞节', '66', '的');

-------------------------------------------------------------------------------------

    CREATE TABLE IF NOT EXISTS `student` (#判断这张表是否存在，若存在，则跳过创建表操作，
     `s_id` varchar(40) NOT NULL, 
    `s_name` varchar(255) default NULL, 
    `s_age` varchar(255) default NULL, 
    `s_msg` varchar(255) default NULL, 
    PRIMARY KEY (`s_id`)) ENGINE=InnoDB DEFAULT CHARSET=utf8;
    INSERT INTO `student` VALUES ('7', '重阳节', '33', '登高赏菊');