import requests
import os
from pypdf import PdfWriter
import shutil

## modify this list to include links to all the pdf files you want to download and combine together
urls = ['https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf', 
        'https://www.w3.org/WAI/ER/tests/xhtml/testfiles/resources/pdf/dummy.pdf']

def download(urls):
    temp_dir = 'tmp'
    if not os.path.exists(temp_dir):
        os.mkdir(temp_dir)
    num = 1
    files = []
    for url in urls:
        files.append(download_pdf(url, num))
        num = num + 1
    combine_pdfs(files)
    shutil.rmtree(temp_dir)

def download_pdf(url, num):
    pdf = requests.get(url).content
    file_path = os.path.join('tmp', 'file' + str(num) + '.pdf')
    with open(file_path, 'wb') as file:
        file.write(pdf)
    return file_path

def combine_pdfs(files):
    merger = PdfWriter()
    for file in files:
        merger.append(file)
        
    merger.write('result.pdf')
    merger.close()

download(urls)