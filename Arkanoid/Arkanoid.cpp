#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

class Object {
public:
    Sprite background, background1, background2, background3, background4, nameGame, buttonPlay, settings, exit, changeTheme, hints, buttonBack, buttonLevel[8],
        levels, player, ball, buttonStart, block[1000], butBack_in_play, blockBlack, win, restart, nextlevel, buttonMenu, life[3], endgame, theme1, theme2, theme3, theme4, lineTheme,
        s1, s2, s3, s4,          // Sprite for standart theme
        bb1, bb2, bb3, bb4,      // Sprite for baseball theme
        sky1, sky2, sky3, sky4,  // Sprite for skystar theme
        bc1, bc2, bc3, bc4       // Sprite for blackcat theme
        
        ;  

    RectangleShape line;
};

class Boolean {
public:
    bool menu = true, setting = false, game = false, pok = true, npok = false, buttonStart = false, play = false, mball = true, rblock[56], startLevel[8],
        win = false, buttonLevel[8], dead = false, changeTheme = false, theme1 = true, theme2 = false, theme3 = false, theme4 = false;

    Boolean() {
        for (int i = 0; i < 56; i++)
            rblock[i] = false;

        for (int i = 0; i < 8; i++)
            startLevel[i] = false;

        buttonLevel[0] = true;
        for (int i = 1; i < 8; i++) {
            buttonLevel[i] = false;
        }
    }
};


int main()
{   
    srand(time(0));

    RenderWindow app(VideoMode(1280, 720), "Arkanoid Game");
    app.setFramerateLimit(60);

    Object game;
    Boolean b;

        // Texture for menu
    Texture m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, 
            m16, m17, m18, m19, m20, m21, m22, m23, m24;
    m1.loadFromFile("images/Standart/background.jpg");  // background
    m2.loadFromFile("images/nametag.png");      // NameGame
    m3.loadFromFile("images/Menu/play.png");       // Button Play
    m4.loadFromFile("images/Menu/settings.png");    // Settings
    m5.loadFromFile("images/Menu/exit.png");        // Exit
    m6.loadFromFile("images/Menu/settings.png");    // Settings Keyboard
    m7.loadFromFile("images/block1.png");      // Hints
    m8.loadFromFile("images/Menu/back.png");        // Button Back
    m9.loadFromFile("images/butlev.png");      // button Level
    m10.loadFromFile("images/heart2.png");     // levels
    m11.loadFromFile("images/baseball/baseplatform.png");     // player/paddle
    m12.loadFromFile("images/baseball/baseball30.png");     // ball
    m13.loadFromFile("images/Menu/play.png");      // buttonStart
    m14.loadFromFile("images/Menu/back.png");       // buttonBack in play
    m15.loadFromFile("images/Menu/play.png");      // 
    m16.loadFromFile("images/baseball/yankees_block.png");     // block in play
    m17.loadFromFile("images/paddle2.png");
    m18.loadFromFile("images/Menu/..png");    // Bar Win
    m19.loadFromFile("images/Menu/restart.png");    // button restart
    m20.loadFromFile("images/Menu/next.png");    // button next level
    m21.loadFromFile("images/Menu/menu.png");    // button menu
    m22.loadFromFile("images/hearts.png");
    m23.loadFromFile("images/gameover.png");
    m24.loadFromFile("images/lineTheme1.png");

    app.draw(game.background);
    // Texture for background
    Texture b1, b2, b3, b4;

    b1.loadFromFile("images/Standart/background.jpg");
    b2.loadFromFile("images/SkyStar/bluetheme.png");
    b3.loadFromFile("images/baseball/yelfield.png");
    b4.loadFromFile("images/BlackCat/backcemetry2.png");

    game.background1.setTexture(b1);
    game.background2.setTexture(b2);
    game.background3.setTexture(b3);
    game.background4.setTexture(b4);

        // Texture for Standart Theme
    Texture s1, s2, s3, s4;
    s1.loadFromFile("images/Standart/background.jpg");
    s2.loadFromFile("images/Standart/ball_beesass.png");
    s3.loadFromFile("images/Standart/platform_purple.png");
    s4.loadFromFile("images/Standart/NewBlock.png");

    game.s1.setTexture(s1);
    game.s2.setTexture(s2);
    game.s3.setTexture(s3);
    game.s4.setTexture(s4);

        // Texture for Baseball theme
    Texture bb1, bb2, bb3, bb4;
    bb1.loadFromFile("images/baseball/yelfield.png");
    bb2.loadFromFile("images/baseball/baseball30.png");
    bb3.loadFromFile("images/baseball/baseplatform.png");
    bb4.loadFromFile("images/baseball/blocks.png");

    game.bb1.setTexture(bb1);
    game.bb2.setTexture(bb2);
    game.bb3.setTexture(bb3);
    game.bb4.setTexture(bb4);

        // Texture for SkyStar theme
    Texture sky1, sky2, sky3, sky4;
    sky1.loadFromFile("images/SkyStar/bluetheme.png");
    sky2.loadFromFile("images/SkyStar/ballskystar.png");
    sky3.loadFromFile("images/SkyStar/platform.png");
    sky4.loadFromFile("images/SkyStar/blocks.png");

    game.sky1.setTexture(sky1);
    game.sky2.setTexture(sky2);
    game.sky3.setTexture(sky3);
    game.sky4.setTexture(sky4);

        // Texture for BlackCat theme
    Texture bc1, bc2, bc3, bc4;
    bc1.loadFromFile("images/BlackCat/backcemetry2.png");
    bc2.loadFromFile("images/BlackCat/blackfatball1.png");
    bc3.loadFromFile("images/BlackCat/cemplatform.png");
    bc4.loadFromFile("images/BlackCat/pumpkinblock.png");

    game.bc1.setTexture(bc1);
    game.bc2.setTexture(bc2);
    game.bc3.setTexture(bc3);
    game.bc4.setTexture(bc4);
     
     
    // Texture theme
    Texture t1, t2, t3, t4;

    t1.loadFromFile("images/Standart/background.jpg");
    t2.loadFromFile("images/SkyStar/bluetheme.png");
    t3.loadFromFile("images/baseball/yelfield.png");
    t4.loadFromFile("images/BlackCat/backcemetry2.png");

    // Position and texture for theme

    game.theme1.setTexture(t1);
    game.theme1.setScale(0.15, 0.15);
    game.theme1.setPosition(100, 200);

    game.theme2.setTexture(t2);
    game.theme2.setScale(0.15, 0.15);
    game.theme2.setPosition(400, 200);

    game.theme3.setTexture(t3);
    game.theme3.setScale(0.15, 0.15);
    game.theme3.setPosition(700, 200);

    game.theme4.setTexture(t4);
    game.theme4.setScale(0.15, 0.15);
    game.theme4.setPosition(1000, 200);

    game.lineTheme.setTexture(m24);
    game.lineTheme.setScale(1, 0.5);
    int px = 100;


    game.background.setTexture(m1);            // Texture for background
    game.nameGame.setTexture(m2);              // Texture for NameGame
    game.nameGame.setScale(0.3, 0.3);          // Scale for NameGame
    game.nameGame.setPosition(380, 40);        // Position (x, y) for NameGame
    game.buttonPlay.setTexture(m3);            // Texture for button Play
    game.buttonPlay.setPosition(510, 200);     // Position (x, y) for button Play
    game.settings.setTexture(m4);              // Texture for button Settings
    game.settings.setPosition(510, 300);       // Position (x, y) for button Settings
    game.exit.setTexture(m5);                  // Texture for button Exit
    game.exit.setPosition(510, 500);           // Position (x, y) for button Exit

    game.changeTheme.setTexture(m6);                   // Texture for button settingKeyboard
    game.changeTheme.setPosition(510, 300);            // Position (x, y) for button settingKeyboard
    game.hints.setTexture(m7);                       
    game.hints.setTextureRect(IntRect(890, 0, 808, 89));
    game.hints.setPosition(220, 400);
    game.buttonBack.setTexture(m8);                       // Texture for button button Back

    game.levels.setTexture(m10);
    game.levels.setPosition(620, 50);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++) {
            game.buttonLevel[j * 4 + i].setTexture(m9);
            game.buttonLevel[j * 4 + i].setTextureRect(IntRect(0, 0, 160, 159));
            game.buttonLevel[j * 4 + i].setPosition(150 + 250 * i, 200 + 200 * j);
        }
    game.buttonLevel[0].setTextureRect(IntRect(0, 159, 160, 160));


    game.player.setTexture(m11);               // Texture from player/paddle
    game.ball.setTexture(m12);                 // Texture from ball
    int kx = 1, ky = 1;

    game.buttonStart.setTexture(m13);          // Texture from button start
    game.buttonStart.setPosition(980, 600);    // Position for button start
    game.butBack_in_play.setTexture(m14);      // Texture from button back in play window
    game.butBack_in_play.setPosition(50, 600); // Position for button back in play window

    game.blockBlack.setTexture(m17);
    int blockBlack = 1;
    int db = 0;
    int nextlevel = 0;

    // Game

    game.line.setSize(Vector2f(1280, 1));
    game.line.setFillColor(Color::Transparent);
    game.line.setPosition(0, 100);

    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 3; j++) {
            game.block[j * 14 + i].setTexture(m16);
            game.block[j * 14 + i].setTextureRect(IntRect(0, 0, 80, 40));
        }

    game.win.setTexture(m18);
    game.win.setPosition(510, 100);
    game.restart.setTexture(m19);
    game.restart.setPosition(510, 200);
    game.nextlevel.setTexture(m20);
    game.nextlevel.setPosition(510, 300);
    game.buttonMenu.setTexture(m21);
    game.buttonMenu.setPosition(510, 400);
    game.endgame.setTexture(m23);
    game.endgame.setPosition(350, 30);

    for (int i = 0; i < 3; i++) {
        game.life[i].setTexture(m22);
        game.life[i].setPosition(10 + 60 * i, 10);
        game.life[i].setScale(1.5, 1.5);
    }

    int life = 3;


    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        
            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left) {
                    if (b.play && b.mball)
                        b.mball = false;

                    Vector2i pos = Mouse::getPosition(app);

                    if (b.menu) {
                        if (pos.x >= 513 && pos.x <= 755 &&
                            pos.y >= 500 && pos.y <= 585)
                            app.close();

                        if (pos.x >= 513 && pos.x <= 755 &&
                            pos.y >= 300 && pos.y <= 385) {
                            b.menu = false;
                            b.setting = true;
                        }

                        if (pos.x >= 513 && pos.x <= 755 &&
                            pos.y >= 200 && pos.y <= 285) {
                            b.menu = false;
                            b.game = true;

                        }
                        game.buttonBack.setPosition(510, 500);
                    }

                    else if (b.setting) {
                        if (pos.x >= 510 && pos.x <= 755 &&
                            pos.y >= 500 && pos.y <= 585) {
                            b.menu = true;
                            b.setting = false;
                        }

                        if (pos.x >= 513 && pos.x <= 755 &&
                            pos.y >= 300 && pos.y <= 385) {
                            b.setting = false;
                            b.changeTheme = true;
                        }

                    }

                    else if (b.changeTheme) {
                        if (pos.x >= 513 && pos.x <= 755 &&
                            pos.y >= 500 && pos.y <= 585) {
                                b.setting = true;
                                b.changeTheme = false;
                        }

                        if (pos.x >= 100 && pos.x <= 292 &&
                            pos.y >= 200 && pos.y <= 347) {
                                b.theme2 = false;
                                b.theme3 = false;
                                b.theme4 = false;
                                b.theme1 = true;
                                
                        }
                        if (pos.x >= 400 && pos.x <= 592 &&
                            pos.y >= 200 && pos.y <= 347) {
                                b.theme1 = false;
                                b.theme3 = false;
                                b.theme4 = false;
                                b.theme2 = true;
                                
                        }

                        if (pos.x >= 700 && pos.x <= 892 &&
                            pos.y >= 200 && pos.y <= 347) {
                                b.theme2 = false;
                                b.theme3 = true;
                                b.theme4 = false;
                                b.theme1 = false;
                                
                        }

                        if (pos.x >= 1000 && pos.x <= 1192 &&
                                pos.y >= 200 && pos.y <= 347) {
                                b.theme3 = false;
                                b.theme4 = true;
                                b.theme1 = false;
                                b.theme2 = false;
                                
                        }

                    }

                    else if (b.game) {
                        if (pos.x >= 510 && pos.x <= 755 &&
                            pos.y >= 600 && pos.y <= 685) {
                            b.menu = true;
                            b.game = false;
                        }

                        for (int i = 0; i < 4; i++)
                            for (int j = 0; j < 2; j++)
                                if (pos.x >= 150 + 250 * i && pos.x <= 310 + 250 * i &&
                                    pos.y >= 250 + 250 * j && pos.y <= 410 + 250 * j &&
                                    b.buttonLevel[j * 4 + i]) {
                                    b.game = false;
                                    b.startLevel[j * 4 + i] = true;
                                    nextlevel = j * 4 + i;

                                    if (b.pok) {
                                        b.npok = true;

                                        game.player.setPosition(450, 500);
                                        game.ball.setPosition(510, 415);
                                    }
                                    else
                                        b.buttonStart = true;
                                }
                    }
                    else if (b.npok) {
                        if (pos.x >= 150 && pos.x <= 395 &&
                            pos.y >= 600 && pos.y <= 685) {
                            b.game = true;
                            b.npok = false;
                        }

                        if (pos.x >= 900 && pos.x <= 1145 &&
                            pos.y >= 600 && pos.y <= 685) {
                            b.buttonStart = true;
                            b.npok = false;
                        }
                    }
                    else if (b.win || b.dead) {
                        if (pos.x >= 510 && pos.x <= 755 &&
                            pos.y >= 200 && pos.y <= 285) {
                            b.win = false;
                            b.buttonStart = true;

                            for (int i = 0; i < 14; i++)
                                for (int j = 0; i < 3; i++)
                                    game.block[j * 14 + i].setPosition(82 * (i + 0.8), 42 * (j + 3.2));
                            db = 0;
                        }

                        if (pos.x >= 510 && pos.x <= 755 &&
                            pos.y >= 300 && pos.y <= 385 && nextlevel < 7 && !b.dead) {
                            b.win = false;
                            b.buttonStart = true;

                            b.startLevel[nextlevel] = false;
                            b.startLevel[nextlevel + 1] = true;
                            nextlevel++;

                            for (int i = 0; i < 14; i++)
                                for (int j = 0; i < 3; i++)
                                    game.block[j * 14 + i].setPosition(82 * (i + 0.8), 42 * (j + 3.2));
                            db = 0;
                        }

                        if (pos.x >= 510 && pos.x <= 755 &&
                            pos.y >= 400 && pos.y <= 485) {
                            b.win = false;
                            b.dead = false;
                            b.menu = true;
                            b.play = false;

                            for (int i = 0; i < 8; i++) {
                                b.startLevel[i] = false;
                            }

                        }


                    }
                 
                    }
                }

                if (b.buttonStart) {
                    b.play = true;
                    b.win = false;
                    b.dead = false;
                    b.mball = true;

                    db = 0;
                    life = 3;


                    for (int i = 0; i < 14; i++)
                        for (int j = 0; j < 3; j++)
                            game.block[j * 14 + i].setPosition(82 * (i + 0.8), 42 * (j + 3.2));


                    for (int i = 14; i < 28; i++)
                        if (b.startLevel[1] || b.startLevel[3] ||
                            b.startLevel[5] || b.startLevel[7]) {
                            game.block[i].setTextureRect(IntRect(80, 0, 80, 40));
                            b.rblock[i] = true;
                        }

                    if (b.startLevel[2] || b.startLevel[3] ||
                        b.startLevel[6] || b.startLevel[7]) {
                        game.blockBlack.setPosition(0, 400);
                    }
                    else {
                        game.blockBlack.setPosition(1400, 400);
                    }

                    game.player.setPosition(440, 600);
                    game.ball.setPosition(510, 560);
                    kx = 1;
                    ky = 1;

                    b.buttonStart = false;
                }

                if (b.npok || (!b.mball && b.play)) {
                    game.ball.move(4 * kx, 4 * ky);
                }

                Vector2f player = game.player.getPosition();
                Vector2f ball = game.ball.getPosition();

                if ((ball.y < 0 && b.npok) || (ball.y < 100 && b.play)) {
                    ky *= -1;
                }
                if (ball.x > 1260 || ball.x < 0) {
                    kx *= -1;
                }

                if (game.ball.getGlobalBounds().intersects(game.player.getGlobalBounds())) {
                    ky *= -1;

                    game.ball.move(0, -0.5);
                }

                if (b.play) {
                    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
                        if (player.x < 1125) {
                            game.player.move(10, 0);

                            if (b.mball)
                                game.ball.move(10, 0);
                        }
                    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
                        if (player.x > 0) {
                            game.player.move(-10, 0);

                            if (b.mball)
                                game.ball.move(-10, 0);
                        }

                    for (int i = 0; i < 60; i++)
                        if (game.ball.getGlobalBounds().intersects(game.block[i].getGlobalBounds())) {
                            ky *= -1;
                            game.ball.move(0, 3 * ky);


                            if (!b.rblock[i]) {
                                game.block[i].setPosition(1300, 0);

                                db++;
                            }
                            else {
                                game.block[i].setTextureRect(IntRect(0, 0, 80, 40));

                                b.rblock[i] = false;
                            }

                        }

                    if (ball.y > 780) {
                        b.mball = true;
                        life--;

                        game.player.setPosition(440, 600);
                        game.ball.setPosition(510, 560);
                    }

                    if (!b.mball) {
                        if (b.startLevel[2] || b.startLevel[3] ||
                            b.startLevel[6] || b.startLevel[7]) {
                            game.blockBlack.move(5 * blockBlack, 0);

                            Vector2f bb = game.blockBlack.getPosition();
                            if (bb.x < 0 || bb.x > 1120) {
                                blockBlack *= -1;
                            }
                            if (game.ball.getGlobalBounds().intersects(game.blockBlack.getGlobalBounds()))
                                ky *= -1;

                    }
                }

                    if (db == 42) {
                        b.win = true;
                        b.play = false;

                        b.buttonLevel[nextlevel + 1] = true;
                    }

                    if (life == 0) {
                        b.play = false;
                        b.dead = true;
                    }

                    if (b.buttonLevel[1])
                        game.buttonLevel[1].setTextureRect(IntRect(160, 160, 160, 160));
                    if (b.buttonLevel[2])
                        game.buttonLevel[2].setTextureRect(IntRect(160 * 2, 160, 160, 160));
                    if (b.buttonLevel[3])
                        game.buttonLevel[3].setTextureRect(IntRect(160 * 3, 160, 160, 160));
                    if (b.buttonLevel[4])
                        game.buttonLevel[4].setTextureRect(IntRect(0, 160 * 2, 160, 160));
                    if (b.buttonLevel[5])
                        game.buttonLevel[5].setTextureRect(IntRect(160, 160 * 2, 160, 160));
                    if (b.buttonLevel[6])
                        game.buttonLevel[6].setTextureRect(IntRect(160 * 2, 160 * 2, 160, 160));
                    if (b.buttonLevel[7])
                        game.buttonLevel[7].setTextureRect(IntRect(160 * 3, 160 * 2, 160, 160));
                }

                if (b.npok) {
                    if (player.x < ball.x && player.x < 1120) {
                        game.player.move(4, 0);
                    }

                    else if (player.x > ball.x) {
                        game.player.move(-4, 0);
                    }
                }

                game.lineTheme.setPosition(px, 330);

                if (b.theme1 && px >= 100) {
                    px = 100;
                    app.draw(game.background1);
                    game.ball.setTexture(s2);
                    game.player.setTexture(s3);
                    for (int i = 0; i < 14; i++)
                        for (int j = 0; j < 3; j++) {
                            game.block[j * 14 + i].setTexture(s4);
                            game.block[j * 14 + i].setTextureRect(IntRect(0, 0, 80, 40));
                        }
                }
                if (b.theme2 && px != 1001) {
                    px = 400;
                    app.draw(game.background2);
                    game.ball.setTexture(sky2);
                    game.player.setTexture(sky3);
                    for (int i = 0; i < 14; i++)
                        for (int j = 0; j < 3; j++) {
                            game.block[j * 14 + i].setTexture(sky4);
                            game.block[j * 14 + i].setTextureRect(IntRect(0, 0, 80, 40));
                        }
                }
                if (b.theme3 && px != 1001) {
                    px = 700;
                    app.draw(game.background3);
                    game.ball.setTexture(bb2);
                    game.player.setTexture(bb3);
                    for (int i = 0; i < 14; i++)
                        for (int j = 0; j < 3; j++) {
                            game.block[j * 14 + i].setTexture(bb4);
                            game.block[j * 14 + i].setTextureRect(IntRect(0, 0, 80, 40));
                        }
                }
                if (b.theme4 && px != 1001) {
                    px = 1000;
                    app.draw(game.background4);
                    game.ball.setTexture(bc2);
                    game.player.setTexture(bc3);
                    for (int i = 0; i < 14; i++)
                        for (int j = 0; j < 3; j++) {
                            game.block[j * 14 + i].setTexture(bc4);
                            game.block[j * 14 + i].setTextureRect(IntRect(0, 0, 80, 40));
                        }
                }
                if (b.menu) {
                    app.draw(game.nameGame);
                    app.draw(game.buttonPlay);
                    app.draw(game.settings);
                    app.draw(game.exit);
                }
                if (b.setting) {
                    app.draw(game.changeTheme);
                    app.draw(game.buttonBack);
                }
                if (b.changeTheme) {
                app.draw(game.theme1);
                app.draw(game.theme2);
                app.draw(game.theme3);
                app.draw(game.theme4);
                app.draw(game.lineTheme);
                app.draw(game.buttonBack);
                }
                if (b.game) {
                    app.draw(game.levels);
                    app.draw(game.buttonBack);
                    game.buttonBack.setPosition(510, 600);
                    for (int i = 0; i < 8; i++)
                        app.draw(game.buttonLevel[i]);
                }
                if (b.npok) {
                    app.draw(game.player);
                    app.draw(game.ball);
                    app.draw(game.butBack_in_play);
                    app.draw(game.buttonStart);
                }
                if (b.play || b.win || b.dead) {
                    app.draw(game.line);

                    if (!b.dead) {
                        app.draw(game.player);
                        app.draw(game.ball);
                    }

                    for (int i = 0; i < 56; i++)
                        app.draw(game.block[i]);

                        app.draw(game.blockBlack);

                    for (int i = 0; i < life; i++)
                        app.draw(game.life[i]);

                    if (b.win || b.dead) {
                        if (!b.dead && b.win) {
                            app.draw(game.win);
                            app.draw(game.restart);
                        }
                        else if (b.dead && !b.win) {
                            app.draw(game.endgame);
                            app.draw(game.restart);
                        }

                        if (nextlevel < 7) {
                            app.draw(game.nextlevel);
                        }
                            app.draw(game.buttonMenu);
                    }
                }

                    app.display();
    }
}