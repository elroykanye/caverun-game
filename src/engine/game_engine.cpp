#include "game_engine.hpp"
#include <thread>

using namespace std;

GameEngine::GameEngine(string player, int rows = 6, int cols = 6) {
    this->rows = rows;
    this->cols = cols;

    this->enter = Position(0,0,rows);
    this->exit = Position(cols - 1, rows - 1, rows);
    Position playerPosition(enter);  
    Position monsterPosition(exit);
    this->player = Player(player, playerPosition);
    this->monster = Monster(monsterPosition);
}

GameEngine::~GameEngine() {
    delete this->roomSys;
    delete this->ui;
}

void GameEngine::render(GtkApplication *app) {
    this->roomSys = new RoomSystem(rows, cols);
    this->ui = new UI(app, rows, cols);
    this->ui->map = this->roomSys->getMap();
    this->ui->player = &player;
    this->ui->monster = &monster;
    this->ui->exit = &exit;
    this->ui->init();
}

void GameEngine::launch() {
    int i = 0;
    auto loopFunc = [this]() {
        int maxX = cols - 1;
        int maxY = rows - 1;
        Position currPlayerPosition = player.getPosition();
        while (true) {
            if (player.getPosition() == exit) {
                string moves = to_string(player.getTotalMoves());
                this->ui->display("GAME WON - you survived in " + moves + " moves!" , Severity::PRIMARY);
                break;
            }

            if (player.getHealth() <= 0) {
                this->ui->display("GAME LOST - you died", Severity::DANGER);
                break;
            }
            if (player.getPosition() == monster.getPosition()) {
                this->ui->display("GAME LOST - you were eaten yo", Severity::DANGER);
                break;
            }
            if (player.getMoves() == 0) { // run the monster move;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                Position monsterMove = monster.sense(player.getPosition(), maxX, maxY);
                monster.move(monsterMove);
                player.setMoves(2);

                this->ui->refresh();
            }
            if (player.getPosition() != player.getNextPosition() && player.getMoves() > 0) {
                // before effects of the move
                if (player.isPoisoned()) {
                    if (player.damage.moves > 0) {
                        player.updateHealth(player.damage.value * -1);
                        player.damage.moves--;
                    }
                }
                // end before effects

                Position playerMove = player.sense(player.getNextPosition(), maxX, maxY);
                if (player.getPosition() != playerMove) {
                    player.move(playerMove);

                    // after effects of the move
                    Room* currRoom = this->ui->map->getRoom(playerMove);
                
                    RoomVisit visit = currRoom->visit(player);
                    this->ui->display(visit.message, visit.result);
                    // end after effects

                    this->ui->refresh();
                }
            }
        }

        this_thread::sleep_for(chrono::seconds(1));
        player.setDone(true);
        this->ui->refresh();
    };

    thread loopThread(loopFunc);
    
    
    loopThread.detach();
}


