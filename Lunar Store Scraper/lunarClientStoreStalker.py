import requests
from bs4 import BeautifulSoup
import time

def getLosers():
    # URL of the webpage
    url = 'https://store.lunarclient.com'

    # Fetch the HTML content of the page
    response = requests.get(url)
    html_content = response.content

    # Parse the HTML content
    soup = BeautifulSoup(html_content, 'html.parser')

    # Find the <body> tag
    info = soup.body.find_all('div', class_='row mb-3')

    img_tags = soup.find_all('img')

    titles = [img.get('title') for img in img_tags]

    return titles

stuff = open('lunarClientStoreStalker.txt', 'r')

allUsers = [stuff.readlines()]

while True:

    storage = open('lunarClientStoreStalker.txt', 'a+')
    for title in getLosers():
        if title is not None:
            if title not in allUsers:
                storage.write(title + '\n')
                print(title)
                allUsers.append(title)    
    storage.close()                
                
    time.sleep(20)
