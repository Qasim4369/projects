use project;

select *from user;
CREATE TABLE User (
  UserID INT,
  Username VARCHAR(255),
  Password VARCHAR(255),
  FirstName VARCHAR(255),
  LastName VARCHAR(255),
  Role VARCHAR(255),
  PRIMARY KEY (UserID)
);

CREATE TABLE Administrator (
  AdministratorID INT PRIMARY KEY,
  UserID INT,
  Username VARCHAR(255),
  Password VARCHAR(255),
  AdminName VARCHAR(255),
  PhoneNo VARCHAR(255) NOT NULL,
  Level VARCHAR(10) CHECK (Level IN ('senior', 'junior')),
  FOREIGN KEY (UserID) REFERENCES User(UserID)
);

CREATE TABLE ProjectManager(
  ManagerID INT PRIMARY KEY,
  ManagerName VARCHAR(255),
  UserID INT,
  PhoneNo VARCHAR(255),
  FOREIGN KEY (UserID) REFERENCES User(UserID)
);

CREATE TABLE Developer (
  DeveloperID INT PRIMARY KEY,
  DeveloperName VARCHAR(255),
  Dev_PhoneNo VARCHAR(255),
  Title VARCHAR(255),
  UserID INT,
  FOREIGN KEY (UserID) REFERENCES User(UserID)
);

-- Create Customer table
CREATE TABLE Customer (
  CustomerID INT PRIMARY KEY,
  CustomerName VARCHAR(255),
  UserID INT,
  FOREIGN KEY (UserID) REFERENCES User(UserID)
);

CREATE TABLE Project (
  ProjectID INT PRIMARY KEY,
  Title VARCHAR(255),
  Description TEXT,
  StartDate DATE,
  EndDate DATE,
  ManagerID INT,
  FOREIGN KEY (ManagerID) REFERENCES ProjectManager(ManagerID)
);

CREATE TABLE Issue (
  IssueID INT PRIMARY KEY,
  IssueType VARCHAR(255),
  Summary VARCHAR(255),
  Description VARCHAR(255),
  ProjectID INT,
  IssueCreatorID INT,
  IssueHandlerID INT,
  Status VARCHAR(10) CHECK (Status IN ('Open', 'Resolved', 'In Progress')),
  PriorityLvL VARCHAR(10),
  DueDate DATE,
  Comments VARCHAR(255),
  Attachments VARCHAR(255),
  FOREIGN KEY (ProjectID) REFERENCES Project(ProjectID),
  FOREIGN KEY (IssueCreatorID) REFERENCES User(UserID),
  FOREIGN KEY (IssueHandlerID) REFERENCES User(UserID)
);


INSERT INTO User (UserID, Username, Password, FirstName, LastName, Role)
VALUES (10001, 'ali123', 'password123', 'Ali', 'Khan', 'Developer'),
	   (10002, 'sara89', 'securepass', 'Sara', 'Ahmed', 'Manager'),
	   (10003, 'asif777', 'mypassword', 'Asif', 'Raza', 'Administrator'),
	   (10004, 'fatima12', 'pass123', 'Fatima', 'Hussain', 'Developer'),
	   (10005, 'umar45', 'strongpass', 'Umar', 'Malik', 'Customer'),
       (10006, 'farah11', 'adminpass', 'Farah', 'Khan', 'Administrator'),
	   (10007, 'ayesha22', 'managerpass' ,'Ayesha', 'Malik',  'Manager'),
	   (10008, 'raheel22', 'admin123', 'Raheel', 'Ahmed', 'Administrator'),
	   (10009, 'zain99', 'adminpass456', 'Zain', 'Malik', 'Administrator'),
	   (10010, 'saad321', 'saaddev', 'Saad', 'Ahmed', 'Developer'),
	   (10011, 'nida77', 'adminpass789', 'Nida', 'Ali', 'Administrator'),
	   (10012, 'usman11', 'manager123', 'Usman', 'Raza', 'Manager'),
       (10013, 'saima342', 'saimadev', 'Saima','Malik', 'Developer'),
       (10014, 'ahmed432', 'custahmed', 'Ahmed', 'Khan', 'Customer'),
       (10015, 'sana111', 'sanamanager12', 'Sana', 'Ahmed', 'Manager'),
       (10016, 'faisal234', 'faisalmanager', 'Faisal', 'Ali', 'Manager'),
       (10017, 'kami123', 'kamdev12', 'Kamran', 'Raza', 'Developer'),
	   (10018, 'sara666', 'sarapass', 'Sara', 'Malik', 'Customer'),
	   (10019, 'kammed54', 'karma123', 'Kamran', 'Ahmed', 'Customer'),
	   (10020, 'ayesh124', 'ayeshapass', 'Ayesha', 'Raza', 'Customer');

INSERT INTO Administrator (AdministratorID, UserID, Username, Password, AdminName, PhoneNo, Level)
VALUES (20001, 10003, 'asif777', 'mypassword', 'Asif Raza', '0300-1234567', 'senior'),
	   (20002, 10006, 'farah11', 'adminpass', 'Farah Khan', '0312-9876543', 'junior'),
	   (20003, 10008, 'raheel22', 'admin123', 'Raheel Ahmed', '0333-4567890', 'senior'),
	   (20004, 10009, 'zain99', 'adminpass456', 'Zain Malik', '0345-6789012', 'junior'),
	   (20005, 10011, 'nida77', 'adminpass789', 'Nida Ali', '0321-3456789', 'senior');

INSERT INTO Project (ProjectID, Title, Description, StartDate, EndDate, ManagerID)
VALUES (1001, 'E-commerce Website', 'Develop an online store for selling products.', '2023-05-01', '2023-08-31', 30001),
	   (1002, 'Inventory Management System', 'Build a system to manage inventory and track stock levels.', '2023-06-15', '2023-10-31', 30002),
	   (1003, 'Customer Relationship Management', 'Create a CRM system to manage customer interactions and sales.', '2023-07-01', '2024-01-31', 30003),
	   (1004, 'Payment Gateway Integration', 'Integrate multiple payment gateways into the system for seamless transactions.', '2023-08-15', '2023-12-31', 30004),
	   (1005, 'Mobile App Development', 'Develop a mobile application for iOS and Android platforms.', '2023-09-01', '2024-03-31', 30005);

INSERT INTO ProjectManager (ManagerID, ManagerName, UserID, PhoneNo)
VALUES (30001, 'Sara Ahmed', 10002, '0300-1112223'),
       (30002, 'Ayesha Malik', 10007, '0311-3334445'),
       (30003, 'Usman Raza', 10012, '0322-5556667'),
       (30004, 'Sana Ahmed', 10015, '0344-7778889'),
       (30005, 'Faisal Ali', 10019, '0355-9990001');
       
INSERT INTO Developer (DeveloperID, DeveloperName, Dev_PhoneNo, Title, UserID)
VALUES (40001, 'Hassan Ali', '0330-1234567', 'Senior Developer', 10001),
       (40002, 'Aisha Khan', '0312-9876543', 'Junior Developer', 10004),
       (40003, 'Saad Ahmed', '0345-6789012', 'Senior Developer', 10010),
       (40004, 'Saima Malik', '0321-3456789', 'Junior Developer', 10013),
       (40005, 'Kamran Raza', '0300-1112223', 'Senior Developer', 10017);

INSERT INTO Customer (CustomerID, CustomerName, UserID)
VALUES (50001, 'Nadia Ali', 10005),
	   (50002, 'Ahmed Khan', 10014),
	   (50003, 'Sara Malik', 10018),
	   (50004, 'Kamran Ahmed', 10019),
	   (50005, 'Ayesha Raza', 10020);

INSERT INTO Issue (IssueID, IssueType, Summary, Description, ProjectID, IssueCreatorID, IssueHandlerID, Status, PriorityLvL, DueDate, Comments, Attachments)
VALUES (60001, 'Bug', 'Null reference exception', 'When clicking on the submit button, a null reference exception is thrown.', 1001, 10005, 10001, 'Open', 'High', '2023-05-20', 'This issue needs to be addressed urgently.', 'issue1_attachment.pdf'),
	   (60002, 'Enhancement', 'Add search functionality', 'The system needs to have a search feature to allow users to search for products.', 1002, 10014, 10004, 'Open', 'Medium', '2023-06-05', 'This enhancement will greatly improve user experience.', 'issue2_attachment.docx'),
	   (60003, 'Bug', 'Incorrect calculation', 'The total price is being calculated incorrectly for some products.', 1003, 10018, 10010, 'In Progress', 'High', '2023-05-25', 'The issue seems to be related to the pricing algorithm.', NULL),
	   (60004, 'Bug', 'Login issue', 'Some users are unable to log in to the system.', 1004, 10007, 10013, 'Resolved', 'Medium', '2023-05-30', 'The issue seems to be related to password hashing.', 'issue4_attachment.png'),
	   (60005, 'Enhancement', 'Add export feature', 'Users should be able to export their data to a CSV file.', 1005, 10009, 10017, 'Open', 'Low', '2023-06-10', 'This enhancement will provide greater flexibility to users.', NULL);

ALTER USER 'root' IDENTIFIED WITH mysql_native_password BY 'password';
flush privileges;