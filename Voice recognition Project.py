#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
from zipfile import ZipFile
from pyunpack import Archive
from pydub import AudioSegment
import os, zipfile
import pandas as pd
import numpy as np
import librosa
import path
from pathlib import Path
from sklearn.model_selection import train_test_split


# In[2]:


file_name = "BS DS Semester Project-20211218T135815Z-001.zip"
with ZipFile(file_name, 'r') as zip: 
     zip.extractall()
print('Unzipped Successfully')  


# In[22]:


os.chdir(r"C:\Users\qasim")
os.getcwd()


# In[23]:


fil=os.listdir('BS DS Semester Project')
fil
way = Path('BS DS Semester Project').absolute()
print(way)


# In[44]:


mfccarr = []
mfccns = []
for i in fil:
    folders = os.listdir(f'{way}/{i}/')
    for j in range(len(folders)):
        audiop = f'BS DS Semester Project/{i}/{folders[j]}'
        X , sr = librosa.load(audiop)
        k = librosa.feature.mfcc(y=X, sr=sr)
        k=k.flatten()
        try:
            mfccr=np.pad(k,(0,7000-len(k)),'constant')
            mfccns.append(i)
            mfccarr.append(mfccr)
        except:
            print('not ok')


# In[45]:


df = pd.DataFrame()
df['Mfcc']=mfccarr
df['Names']=mfccns
df


# In[46]:


from sklearn.preprocessing import LabelEncoder
le=LabelEncoder()
df['Label']=le.fit_transform(df.Names)
df


# In[39]:


newarray = np.array(mfccarr)
data = pd.DataFrame(newarray)
data


# In[49]:


X = newarray
y = df["Label"]
print('Shape of X = ', X.shape)
print('Shape of y = ', y.shape)


# In[68]:


X_train, X_test, y_train, y_test =train_test_split(X, y, test_size=0.22, random_state=51)
print('Shape of X_train = ', X_train.shape)
print('Shape of y_train = ', y_train.shape)
print('Shape of X_test = ', X_test.shape)
print('Shape of y_test = ', y_test.shape)


# In[31]:


import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import MinMaxScaler


# In[32]:


sc = StandardScaler()
sc.fit(X_train)
X_train_sc = sc.transform(X_train)
X_test_sc = sc.transform(X_test)


# In[61]:


from sklearn import tree
dec_clf = tree.DecisionTreeClassifier()
dec_clf = dec_clf.fit(X_train, y_train)
pred=dec_clf.predict(X_test)
dec_clf.score(X_test,y_test)
print ("Accuracy : " , accuracy_score(y_test,pred)*100)  
print("Report : \n", classification_report(y_test, pred))
print("F1 Score : ",f1_score(y_test, pred, average='macro')*100)


# In[34]:


from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import f1_score
from sklearn.metrics import classification_report 
print ("Accuracy : " , accuracy_score(y_test,pred)*100)  
print("Report : \n", classification_report(y_test, pred))
print("F1 Score : ",f1_score(y_test, pred, average='macro')*100)


# In[52]:


from sklearn.neighbors import KNeighborsClassifier
clf1=KNeighborsClassifier()
clf1.fit(X_train, y_train)
pred=clf1.predict(X_test)
clf1.score(X_test,y_test)
clf1=KNeighborsClassifier()
clf1.fit(X_train_sc,y_train)
pred=clf1.predict(X_test_sc)
clf1.score(X_test_sc,y_test)


# In[53]:


from sklearn.decomposition import PCA

pca=PCA(n_components=3)
X_trainn=pca.fit_transform(X_train_sc)
X_testt=pca.transform(X_test_sc)


# In[63]:


from sklearn.datasets import load_iris
iris = load_iris()

X = iris.data
y = iris.target

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=1)

from sklearn.naive_bayes import GaussianNB
gnb = GaussianNB()
gnb.fit(X_train, y_train)
y_pred = gnb.predict(X_test)
 
from sklearn import metrics
print("Gaussian Naive Bayes model accuracy(in %):", metrics.accuracy_score(y_test, y_pred)*100)


# In[67]:


from sklearn.datasets import load_iris
from sklearn.linear_model import LogisticRegression
X, y = load_iris(return_X_y=True)
clf = LogisticRegression(random_state=0).fit(X, y)
clf.predict(X[:2, :])
clf.predict_proba(X[:2, :])
clf.score(X, y)


# In[66]:


import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.model_selection import train_test_split

from sklearn.metrics import accuracy_score
from sklearn.ensemble import RandomForestClassifier
iris = datasets.load_iris()
X = iris.data[:, 2:]
y = iris.target
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1, stratify=y)

forest = RandomForestClassifier(criterion='gini',
                                 n_estimators=5,
                                 random_state=1,
                                 n_jobs=2)
forest.fit(X_train, y_train)

y_pred = forest.predict(X_test)
print('Accuracy: %.3f' % accuracy_score(y_test, y_pred))
print ("Accuracy : " , accuracy_score(y_test,pred)*100)  
print("Report : \n", classification_report(y_test, pred))
print("F1 Score : ",f1_score(y_test, pred, average='macro')*100)


# In[69]:


get_ipython().system('pip install flask')


# In[ ]:




