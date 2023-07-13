#!/usr/bin/env python
# coding: utf-8
from sklearn.model_selection import train_test_split
from PIL import Image,ImageOps,ImageFile
from sklearn.ensemble import RandomForestClassifier
from sklearn.datasets import make_classification
import pandas as pd
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import f1_score
from sklearn.metrics import classification_report
from skimage.transform import resize
from skimage import filters
import numpy as np
import pickle
from sklearn.neighbors import KNeighborsClassifier
import tensorflow as tf
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.models import load_model
from tensorflow.keras.models import Sequential
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.preprocessing.image import load_img , img_to_array
from tensorflow.keras.layers import Dense , Dropout , Conv2D , MaxPooling2D, Flatten , BatchNormalization

df_1 = pd.read_csv('labels.csv')
df_1.drop('text_ocr', inplace = True, axis =1)
df_1.drop('text_corrected', inplace = True, axis =1)

df_1.info()
img=df_1['image_name']


ImageFile.LOAD_TRUNCATED_IMAGES = True
images = []

for i in img[:1500]:
    print(i)
    image = Image.open('C:\\Users\\hp\\Desktop\\Uni\\IDS\\images'+'\\'+i)
    image = image.resize((200,200))
    gray_image = ImageOps.grayscale(image)
    expanded_image_grayscale = np.expand_dims(gray_image, axis=2)
    image_flat = np.array(expanded_image_grayscale).flatten()
    images.append(image_flat)


data=[]
data=images
y = (data-np.min(data))/(np.max(data)-np.min(data))

labels = df_1['overall_sentiment'] 
x=[]
for i in labels:
    if(i == 'very_positive'):
        x.append(0)
    if(i == 'positive'):
        x.append(0)
    if(i == 'negative'):
        x.append(2)
    if(i == 'very_negative'):
        x.append(2)
    if(i == 'neutral'):    
        x.append(1)


x_train,x_test,y_train,y_test = train_test_split(y[:1500],x[:1500],test_size=0.2,random_state=42)


clf = KNeighborsClassifier()
clf = clf.fit(x_train[:1500], y_train[:1500])

pickle.dump(clf, open("model.pkl", "wb"))