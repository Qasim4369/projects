#Qasim Shafiq
library(readr)
library(tidyverse)
library(dplyr)
library(data.table)
library(lubridate)
library(ggplot2)
library(lattice)
library(caret)
Detailed_Dataset <- read.csv("/Detailed_Dataset.csv")
data<-Detailed_Dataset
#--------------------------------------------Q1----------------------------------------------------------
# Does the purchase amount of the customers increase over the period of time?
# Mean=The Average Purchase made by the Customers
# H0 : mean2-mean1= 0  HA: mean2-mean1 will be not equal to 0
m <- c(mean(data$w1_total_sales),mean(data$w2_total_sales),mean(data$w3_total_sales),mean(data$w4_total_sales),mean(data$w4_total_sales))
barplot(m, xlab="# of Weeks", ylab="Total Sales",)
# As from the graph , you can see that there is increase in the average
#sales. (from week1 - week5)
t.test(data$w5_total_sales,data$w1_total_sales,paired = TRUE)
# So we can conclude that p-value is lesser than the alpha value of 0.05 so we reject Null Hypothesis
#--------------------------------------------Q2----------------------------------------------------------
#As this data set doesn't have Categories(Rich,Poor,Mediocre) we will divide the customers then
#on basis of quantile
# Ho: label and status are independent
# Ha: Label and status are dependent

q1<-quantile((Detailed_Dataset$total_revenue),0.25)

q2<-quantile((Detailed_Dataset$total_revenue),0.50)

q3<-quantile((Detailed_Dataset$total_revenue),0.75)

q4<-quantile((Detailed_Dataset$total_revenue),1)
Detailed_Dataset<-Detailed_Dataset %>%
  mutate(Category  = case_when(
    Detailed_Dataset$total_revenue < q1 ~ "Poor",
    Detailed_Dataset$total_revenue > q1 & Detailed_Dataset$total_revenue < q3 ~ "Mediocre",
    Detailed_Dataset$total_revenue > q3 ~ "Rich"
  ))
chrnd<- data.frame(filter(Detailed_Dataset,label=="churned"))
bp<-table(chrnd$label,chrnd$Category)
barplot(bp)
chisq.test(bp)
# As the P val is less then the alpha value so we reject the null Hypothesis.
#i.e. Status and Label are dependent
#--------------------------------------------Q3----------------------------------------------------------
#We believe that the churned customers visit the stores occasionally. Verify.
mn<-mean(Detailed_Dataset$total_visit_days)
mn
# H0=mn>5
#Ha=mn<5
# Greater than 5 mean that customer is frequent
# Less than 5 mean that customer is not frequent they visits occasionally.
#Building Information
mean(chrnd$total_visit_days)
sd(chrnd$total_visit_days)
#Visualizing the information
hist(chrnd$total_visit_days)
t.test(chrnd$total_visit_days,mu=5,alternative = 'greater')
#As the P value is equal to 1 we can accept that churned customers visit the store occasionally
#--------------------------------------------Q4----------------------------------------------------------
#Overall spending of churned customers is significantly lesser than the non-churned customers.
#Verify.
#Ho = overall spending of churned customers are greater than or equal then spending non-churned customers
#i.e.mean(spending of churned Customer)-mean(spending of non-churned Customer)>=0
#Ha = overall spending of churned customers is less than overall spending of non-churned customers
#i.e.mean(spending of churned Customer)-mean(spending of non-churned Customer)<0
chrndsp<-Detailed_Dataset$total_revenue[Detailed_Dataset$label=='churned']
nonchrndsp<-Detailed_Dataset$total_revenue[Detailed_Dataset$label=='not churned']
#Checking the weights.
barplot(chrndsp)
barplot(nonchrndsp)
t.test(chrndsp,nonchrndsp,alternative = 'less')
#As the P value is less then the Alpha value so we reject the null hypothesis 
#i.e. overall spending of churned customers is less than non churned ones.
#--------------------------------------------Q5----------------------------------------------------------
dummy_data<-Detailed_Dataset
model <- lm(total_revenue ~ label, data = dummy_data)
summary(model)
coef(model)
pred <- fitted.values(model)
res <- residuals(model)
qplot(pred,res)+geom_point()+geom_smooth(method = "lm" ,se=F)
predict(model,newdata = Detailed_Dataset)

