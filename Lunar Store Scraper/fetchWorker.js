self.onmessage = function() {
    Promise.all([
      fetch('names.txt').then(response => response.text()),
      fetch('times.txt').then(response => response.text())
    ])
    .then(data => {
      self.postMessage({
        status: 'success',
        names: data[0],
        times: data[1]
      });
    })
    .catch(error => {
      self.postMessage({
        status: 'error',
        message: error.message
      });
    });
  };
  