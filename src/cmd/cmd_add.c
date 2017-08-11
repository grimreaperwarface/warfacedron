/**
 * WarfaceBot, a blind XMPP client for Warface (FPS)
 * Copyright (C) 2015-2017 Levak Borok <levak92@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <wb_xmpp_wf.h>
#include <wb_cmd.h>

void cmd_add(const char *nickname)
{
    if (nickname == NULL)
        return;

    xmpp_iq_send_invitation(nickname,
                            NOTIF_FRIEND_REQUEST,
                            NULL, NULL);
}

void cmd_add_wrapper(const char *nickname)
{
    cmd_add(nickname);
}

int cmd_add_completions(struct list *l)
{
    complete_gameroom_players(l);
    complete_clanmates(l);

    return 1;
}
