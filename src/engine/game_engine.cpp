#include "game_engine.hpp"
#include <thread>

using namespace std;

GameEngine::GameEngine(string player, int rows = 6, int cols = 6) {
    this->rows = rows;
    this->cols = cols;

    this->enter = Position(0,0,rows);
    this->exit = Position(cols - 1, rows - 1, rows);
    
    this->monster.setPosition(exit);
    this->player.setPosition(enter);
    this->player.setName(player);
}

GameEngine::~GameEngine() {
}

void GameEngine::render(GtkApplication *app) {
    this->roomSys = new RoomSystem(rows, cols);
    this->scoreBoard = new ScoreBoard();
    this->ui = new UI(app, rows, cols);
    this->ui->map = this->roomSys->getMap();
    this->ui->player = &player;
    this->ui->monster = &monster;
    this->ui->enter = &enter;
    this->ui->exit = &exit;

    this->ui->init();
    this->ui->setup();
    this->ui->displayScores(this->scoreBoard->toString());
}

void GameEngine::launch() {
    int i = 0;
    auto loopFunc = [this]() {
        int maxX = cols - 1;
        int maxY = rows - 1;
        Position currPlayerPosition = player.getPosition();
        while (true) {
            if (player.isDone()) continue;
            if (player.getPosition() == exit && !player.isDone()) {
                string moves = to_string(player.getTotalMoves());
                this->ui->display("GAME WON - you survived in " + moves + " moves!" , Severity::PRIMARY);

                this->ui->refresh();
                ScoreEntry entry = {player.getName(), player.getScore(this->getBoardSize())};
                this->scoreBoard->addScore(entry);
                this->ui->displayScores(this->scoreBoard->toString());

                player.setMoves(2);
                player.setDone(true);
                this->ui->refresh();
            }

            if (player.getHealth() <= 0 && !player.isDone()) {
                this->ui->display("GAME LOST - you died", Severity::DANGER);
                this->ui->refresh();
                player.setDone(true);
            }
            if (player.getPosition() == monster.getPosition() && !player.isDone()) {
                this->ui->display("GAME LOST - you were eaten yo", Severity::DANGER);
                this->ui->refresh();
                player.setDone(true);
            }
            if (player.getMoves() == 0 && !player.isDone()) { // run the monster move;
                this_thread::sleep_for(chrono::seconds(1));
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
    };

    thread loopThread(loopFunc);
    
    
    loopThread.detach();
}

double GameEngine::getBoardSize() const {
    return rows * cols;
}
