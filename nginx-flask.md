# Nginx Flask Tutorial

```
cd ~/pyivp
source docker_run.sh
```

## Nginx

To start:
```
nginx
```

To stop:
```
nginx -s stop
```

In Docker/dockerfile, we copy the default file to /etc/nginx/sites-enabled/, 
and the default html path is set to ~/pyivp/flask

Now open a browser, and enter "http://127.0.0.1/test.html/"

If your workstation has a static IP, you could do "http://[IP]/test.html/"

## Flask

To run Nginx and Flask together
```
source source flask/nginx-flask-hello.sh
```

Open a browser and enter: "http://127.0.0.1:5000/"

Note that the flask currently only works locally. 
This should be able to configured in the nginx setup.

