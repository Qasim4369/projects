import os
import uuid
import flask
import urllib
from PIL import Image
import keras
from tensorflow.keras.models import load_model
from flask import Flask, render_template, request, send_file
from tensorflow.keras.preprocessing.image import load_img, img_to_array
import pickle
from skimage.transform import resize
from skimage import filters
from PIL import Image,ImageOps,ImageFile
ImageFile.LOAD_TRUNCATED_IMAGES = True
import numpy as np

app = Flask(__name__)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
model = pickle.load(open("model.pkl", "rb"))

def ValuePredictor(to_predict_list):
    to_predict = np.array(to_predict_list).reshape(1, 12)
    loaded_model = pickle.load(open("model.pkl", "rb"))
    result = loaded_model.predict(to_predict)
    return result[0]
 
@app.route('/result', methods = ['POST'])
def result():
    if request.method == 'POST':
        to_predict_list = request.form.to_dict()
        to_predict_list = list(to_predict_list.values())
        to_predict_list = list(map(int, to_predict_list))
        result = ValuePredictor(to_predict_list)       
        if int(result)>3:
            prediction ='Recommended'
        else:
            prediction ='Not Recommended'           
        return render_template("results.html", prediction = prediction)

