// Global Declrations
const cards = Array.from(document.querySelectorAll('.popular-reads .card'));
const winHeight = window.innerHeight;

// Highlight selected card
cards.forEach(card => {
    card.addEventListener('mouseover', () => card.classList.add('card-highlight'));
    card.addEventListener('mouseout', () => card.classList.remove('card-highlight'));
});

// Add a go-to-top button
document.addEventListener('DOMContentLoaded', () => {
    const pageFooter = document.querySelector('.page-footer');
    const upButton = document.createElement('button');
    const buttonLink = document.createElement('a');
    const textHolder = document.createElement('span');
    textHolder.textContent = 'Top';
    
    // Styling the button
    upButton.classList.add('go-to-top');

    // Adding the go-to-top button to the DOM
    buttonLink.appendChild(textHolder);
    upButton.appendChild(buttonLink);
    pageFooter.appendChild(upButton);
    
    // Going to the top of the page
    upButton.onclick = () => window.scrollTo({ top: 0, behavior: 'smooth' });
    
    // Hide the button if it's in the fold of the page
    window.onscroll = () => {
        if (document.documentElement.scrollTop > winHeight * 0.3 || document.body.scrollTop > winHeight * 0.3)
            upButton.style.position = 'fixed';
        else
            upButton.style.position = 'static';
        
    };
});
