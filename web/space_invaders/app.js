const width = 15
const height = 15

const grid = document.querySelector('.grid')
const pointsDisplay = document.querySelector('.points')


// creating squares
for (let i = 0; i < width * height; i++) {
    const square = document.createElement('div')
    grid.appendChild(square)
}