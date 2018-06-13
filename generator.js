const fs = require('fs');

const walkSync = (dir, fileList = []) => {
	fs.readdirSync(dir).forEach(file => {
		if (fs.statSync(dir + file).isDirectory()) {
			fileList = walkSync(dir + file + '/', fileList);
			return;
		}
		
		fileList.push(dir + file);
	});
	
	return fileList;
};

let projectFiles = walkSync('src/', ['main.cpp']);
console.log('Number of files: ' + projectFiles.length);

let output = projectFiles.reduce((acc, filename) => {
	return acc + '// ' + filename + '\n' + fs.readFileSync(filename, 'utf-8') + '\n\n';
}, '');

fs.writeFileSync('generated.txt', output);